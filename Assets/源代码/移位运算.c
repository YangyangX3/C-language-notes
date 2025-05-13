#include <stdio.h>

// 辅助函数：打印整数的二进制表示
void print_binary(int num)
{
    for (int i = 31; i >= 0; i--)
    {
        printf("%d", (num >> i) & 1);
        if (i % 4 == 0)
            printf(" "); // 每4位加空格
    }
    printf("\n");
}

int main()
{
    // 移位运算 << 和 >>
    printf("\n移位运算:\n");
    int shift_val = 10; // 二进制: 0000 0000 0000 1010
    printf("原始值: %2d → ", shift_val);
    print_binary(shift_val);

    // 左移 << (相当于乘以2的幂)
    int left_shift = shift_val << 2; // 1010 << 2 = 101000 (40)
    printf("左移2位: %2d → ", left_shift);
    print_binary(left_shift);

    // 右移 >> (相当于除以2的幂)
    int right_shift = shift_val >> 1; // 1010 >> 1 = 0101 (5)
    printf("右移1位: %2d → ", right_shift);
    print_binary(right_shift);

    return 0;
}
