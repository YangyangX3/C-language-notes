#include <stdio.h>

int main()
{
    // 1. 准备一个数组，就像我们的 "积木城堡"
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]); // 计算数组元素的个数

    // 2. 指针的声明和初始化
    // 创建一个指针变量 p，让它指向数组 arr 的第一个元素 (arr[0])
    // 就像拿到一张指向城堡入口的地图
    int *p = arr; // 或者写成 int *p = &arr[0]; 效果一样

    printf("--- 指针初始化与解引用 ---\n");
    printf("数组 arr 的地址: %p\n", arr);
    printf("指针 p 指向的地址: %p\n", p);
    printf("指针 p 指向的第一个元素的值 (*p): %d\n", *p); // 解引用：拿出地图指向的那个房间里的东西

    // 3. 通过指针访问数组元素
    printf("\n--- 通过指针访问数组元素 ---\n");
    printf("*(p + 0) 的值 (即 *p): %d\n", *(p + 0));
    printf("*(p + 1) 的值 (即 arr[1]): %d\n", *(p + 1)); // p+1 指向第二个元素
    printf("*(p + 2) 的值 (即 arr[2]): %d\n", *(p + 2)); // p+2 指向第三个元素

    // 注意：arr[i] 在底层实际上就是被解释为 *(arr + i)

    // 4. 指针的移动 (自增/自减)
    printf("\n--- 指针的移动 (自增/自减) ---\n");
    printf("初始时 p 指向: %p, 值为: %d\n", p, *p);

    // p++: 先使用 p 当前的值，然后将 p 向后移动一个元素的位置
    printf("执行 p++ 后...\n");
    p++; // p 现在指向 arr[1]
    printf("p 指向: %p, 值为: %d\n", p, *p);

    // ++p: 先将 p 向后移动一个元素的位置，然后使用 p 移动后的值
    printf("执行 ++p 后...\n");
    ++p; // p 现在指向 arr[2]
    printf("p 指向: %p, 值为: %d\n", p, *p);

    // p--: 先使用 p 当前的值，然后将 p 向前移动一个元素的位置
    printf("执行 p-- 后...\n");
    p--; // p 现在指向 arr[1]
    printf("p 指向: %p, 值为: %d\n", p, *p);

    // 5. 指针加减整数
    // 指针加/减整数 N，实际上是移动 N * sizeof(指向的类型) 个字节
    printf("\n--- 指针加减整数 ---\n");
    p = arr; // 将 p 重置回指向 arr[0]
    printf("重置后 p 指向: %p, 值为: %d\n", p, *p);

    int *p_plus_3 = p + 3; // 计算 p 向后移动 3 个元素后的地址
    printf("p + 3 指向的地址: %p\n", p_plus_3);
    printf("*(p + 3) 的值 (即 arr[3]): %d\n", *p_plus_3);

    // 指向最后一个元素
    int *p_last = p + (n - 1);
    printf("p + %d 指向的地址 (最后一个元素): %p\n", n - 1, p_last);
    printf("*(p + %d) 的值 (即 arr[%d]): %d\n", n - 1, n - 1, *p_last);

    // 6. 两个指针相减
    // 只有指向同一个数组（或内存块）内的两个指针相减才有意义
    // 结果是两个指针之间相隔的元素的数量
    printf("\n--- 两个指针相减 ---\n");
    int *p1 = &arr[1]; // 指向第二个元素
    int *p2 = &arr[4]; // 指向第五个元素 (最后一个)

    printf("p1 指向 arr[1] 的地址: %p\n", p1);
    printf("p2 指向 arr[4] 的地址: %p\n", p2);

    // 计算 p2 和 p1 之间隔了多少个元素
    long diff = p2 - p1;                         // 注意结果类型通常是 long 或 ptrdiff_t
    printf("p2 - p1 (元素个数差): %ld\n", diff); // 应该是 3 (元素 4 - 元素 1)

    diff = p1 - p2;
    printf("p1 - p2 (元素个数差): %ld\n", diff); // 应该是 -3

    // 7. 指针比较
    // 可以比较指向同一个数组内的两个指针的大小 (地址先后)
    printf("\n--- 指针比较 ---\n");
    if (p1 < p2)
    {
        printf("p1 的地址在 p2 之前。\n");
    }
    else
    {
        printf("p1 的地址不在 p2 之前。\n");
    }

    // 8. 指向常量的指针 vs 指针常量 (补充知识)
    printf("\n--- 补充知识 ---\n");
    int x = 100, y = 200;
    const int *ptr_to_const = &x; // 指向常量的指针
    // *ptr_to_const = 150; // 错误！不能通过这个指针修改 x 的值
    ptr_to_const = &y; // 正确！指针本身可以指向别处

    int *const const_ptr = &x; // 指针常量
    *const_ptr = 150;          // 正确！可以通过这个指针修改 x 的值 (现在 x 是 150)
    // const_ptr = &y;       // 错误！指针本身不能指向别处

    printf("现在 x 的值是: %d\n", x);

    return 0;
}
