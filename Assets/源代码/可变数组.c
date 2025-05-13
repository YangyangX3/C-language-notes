#include <stdio.h>
#include <stdlib.h>

/*
 * 动态数组结构体
 * arr - 指向动态分配的数组内存
 * size - 当前数组的容量(不是元素个数)
 */
typedef struct
{
    int *arr;
    int size;
} Array;

const int BLOCK_SIZE = 20; // 每次扩容的基本单位

/*
 * 函数声明部分
 * 每个函数的具体功能说明
 */

/* 创建一个初始容量为init_size的动态数组 */
Array array_create(int init_size);

/* 释放动态数组内存，避免内存泄露 */
void array_free(Array *a);

/* 获取数组当前容量 */
int array_size(const Array *array);

/*
 * 获取下标index元素的地址
 * 会自动检查边界并在需要时扩容
 */
int *array_at(Array *array, int index);

/* 安全获取元素值(不检查边界) */
int array_get(const Array *arr, int index);

/* 设置指定位置的元素值 */
void array_set(Array *arr, int index, int num);

/* 数组扩容函数(核心算法) */
void array_inflate(Array *array, int new_size);

/* 主函数 - 测试动态数组功能 */
int main()
{
    // 初始化测试
    Array myArray = array_create(100);
    printf("初始容量: %d\n", array_size(&myArray));

    int number;
    int cnt = 0;
    while (number != -1)
    {
        printf("请输入数字(-1退出):");
        scanf("%d", &number);
        if (number != -1)
        {
            printf("存入[%d]=%d\n", cnt, *array_at(&myArray, cnt) = number);
            cnt++;
        }
    }

    array_free(&myArray); // 程序结束前释放内存
    return 0;
}

/*
 * 创建动态数组
 * init_size - 初始容量
 * 返回: 初始化后的Array结构体
 */
Array array_create(int init_size)
{
    Array newArray;
    newArray.arr = (int *)malloc(init_size * sizeof(int));
    newArray.size = init_size;
    return newArray;
}

/*
 * 释放动态数组内存
 * a - 指向要释放的Array结构体
 * 注意: 调用后会清空数组指针
 */
void array_free(Array *a)
{
    free(a->arr);
    a->arr = NULL;
    a->size = 0;
}

/*
 * 获取当前数组容量
 * array - 要查询的数组
 * 返回: 数组的当前容量(size)
 */
int array_size(const Array *array)
{
    return array->size;
}

/*
 * 访问元素地址(带自动扩容)
 * array - 目标数组
 * index - 要访问的下标
 * 返回: 元素地址(扩容失败返回NULL)
 */
int *array_at(Array *array, int index)
{
    if (index >= array->size) // 需要扩容
    {
        // index / BLOCK_SIZE求出index占满了多少个block，加一得到溢出的那个block
        array_inflate(array, BLOCK_SIZE);
    }
    return &array->arr[index];
}

/*
 * 数组扩容实现
 * array - 要扩容的数组
 * new_size - 要增加的大小(不是总大小)
 */
void array_inflate(Array *array, int new_size)
{
    // 1. 分配新内存空间
    int *p = (int *)malloc(sizeof(int) * (array->size + new_size));

    // 2. 复制旧数据
    for (int i = 0; i < array->size; i++)
    {
        p[i] = array->arr[i];
    }

    // 3. 释放旧内存
    free(array->arr);

    // 4. 更新数组信息
    array->arr = p;
    array->size += new_size;
}

/*
 * 获取元素值(不安全)
 * arr - 源数组
 * index - 元素下标
 * 返回: 元素值
 * 注意: 不检查边界，调用者需确保index有效
 */
int array_get(const Array *arr, int index)
{
    return arr->arr[index];
}

/*
 * 设置元素值
 * arr - 目标数组
 * index - 要设置的下标
 * num - 要设置的值
 * 注意: 不检查边界，调用者需确保index有效
 */
void array_set(Array *arr, int index, int num)
{
    arr->arr[index] = num;
}