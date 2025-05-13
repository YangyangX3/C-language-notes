#include <stdio.h>
#include "max.h" // 包含 max.h 以获取 max 函数声明和 gAll 声明

int main(void)
{
    int a = 5;
    int b = 6;
    printf("%d\n", max(a, b)); // 调用 max 函数
    // 也可以访问在 max.c 中定义的全局变量 gAll (如果需要)
    printf("全局变量 gAll 的值: %d\n", gAll);
    return 0;
}