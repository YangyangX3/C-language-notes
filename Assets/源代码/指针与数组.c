#include <stdio.h>
#include <stddef.h> // For size_t

// 函数接收一个看起来像数组的参数，并打印其 sizeof
// 注意：int arr[] 等价于 int *arr
void processArray(int arr[], size_t sizeFromCaller)
{
    printf("\n--- 进入 processArray 函数 ---\n");
    // 下一行会触发编译器警告 [-Wsizeof-array-argument]，这是正常的，因为它确认了 arr 在这里是作为指针处理的
    printf("函数内 sizeof(arr) (实际为 sizeof(int*)): %zu 字节\n", sizeof(arr));

    // 尽管 arr 是指针，仍然可以使用数组下标访问
    printf("使用 arr[i] 访问元素:\n");
    for (size_t i = 0; i < sizeFromCaller; ++i)
    {
        printf("arr[%zu] = %d (地址: %p)\n", i, arr[i], (void *)&arr[i]);
        // arr[i] 等价于 *(arr + i)
        printf("*(arr + %zu) = %d\n", i, *(arr + i));
    }
    printf("------------------------------------\n");
}

int main()
{
    int numbers[5] = {10, 20, 30, 40, 50};
    int *ptr = numbers; // 指针 ptr 指向数组 numbers 的第一个元素
    int *anotherPtr;

    printf("--- 进入 main 函数 ---\n");

    // 1. sizeof 区别
    printf("main 函数内 sizeof(numbers) (整个数组): %zu 字节\n", sizeof(numbers)); // 整个数组的大小
    printf("main 函数内 sizeof(ptr) (指针变量): %zu 字节\n", sizeof(ptr));         // 指针变量自身的大小
    printf("数组 numbers 的元素个数: %zu\n", sizeof(numbers) / sizeof(numbers[0]));

    // 2. 数组名退化为指针 & 地址比较
    printf("数组 'numbers' 的地址 (&numbers): %p\n", (void *)&numbers);
    printf("数组名 'numbers' 的值 (退化为 &numbers[0]): %p\n", (void *)numbers);
    printf("首元素地址 (&numbers[0]): %p\n", (void *)&numbers[0]);
    printf("指针 'ptr' 的值: %p\n", (void *)ptr);
    printf("指针变量 'ptr' 自身的地址 (&ptr): %p\n", (void *)&ptr);
    // 注意：虽然 &numbers 和 numbers (退化后) 的地址值相同，但类型不同
    // &numbers 的类型是 int (*)[5] (指向包含5个int的数组的指针)
    // numbers 退化后的类型是 int* (指向int的指针)
    printf("(&numbers + 1) 指向的地址: %p (跳过整个数组)\n", (void *)(&numbers + 1));
    printf("(numbers + 1) 指向的地址: %p (跳过一个元素)\n", (void *)(numbers + 1));

    // 3. 调用函数，演示数组参数退化
    processArray(numbers, sizeof(numbers) / sizeof(numbers[0]));

    // 4. 下标运算与指针算术等价
    printf("\n--- 下标运算与指针算术等价性 ---\n");
    int index = 2;
    printf("使用下标访问: numbers[%d] = %d\n", index, numbers[index]);
    printf("使用指针算术: *(numbers + %d) = %d\n", index, *(numbers + index));
    printf("使用指针下标: ptr[%d] = %d\n", index, ptr[index]);
    printf("使用指针算术: *(ptr + %d) = %d\n", index, *(ptr + index));

    // 5. 数组名不可赋值，指针可赋值
    printf("\n--- 可变性演示 ---\n");
    // numbers = anotherPtr; // 错误！数组名不是可修改的左值
    anotherPtr = numbers; // 正确，指针可以被赋值
    printf("anotherPtr 现在指向 numbers: %p\n", (void *)anotherPtr);
    anotherPtr = &numbers[3]; // 指针可以指向数组的其他元素
    printf("anotherPtr 现在指向 numbers[3]: %p, 值: %d\n", (void *)anotherPtr, *anotherPtr);
    printf("----------------------\n");

    return 0;
}
