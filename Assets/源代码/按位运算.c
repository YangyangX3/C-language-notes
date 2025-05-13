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
    int a = 5; // 二进制: 0000 0000 0000 0101
    int b = 3; // 二进制: 0000 0000 0000 0011

    printf("初始值:\n");
    printf("a = %2d → ", a);
    print_binary(a);
    printf("b = %2d → ", b);
    print_binary(b);

    // 1. 按位与 &
    printf("\n按位与 &: a & b\n");
    int result_and = a & b; // 0101 & 0011 = 0001 (1)
    printf("结果: %2d → ", result_and);
    print_binary(result_and);

    // 2. 按位或 |
    printf("\n按位或 |: a | b\n");
    int result_or = a | b; // 0101 | 0011 = 0111 (7)
    printf("结果: %2d → ", result_or);
    print_binary(result_or);

    // 3. 按位取反 ~
    printf("\n按位取反 ~: ~a\n");
    int result_not = ~a; // ~0101 = 1111 1111 1111 1010 (-6的补码)
    printf("结果: %2d → ", result_not);
    print_binary(result_not);

    // 4. 按位异或 ^
    printf("\n按位异或 ^: a ^ b\n");
    int result_xor = a ^ b; // 0101 ^ 0011 = 0110 (6)
    printf("结果: %2d → ", result_xor);
    print_binary(result_xor);

    // 实际应用示例
    printf("\n实际应用:\n");
    // 切换特定位（第3位）
    int flags = 0b0000;
    printf("初始flags: ");
    print_binary(flags);
    flags ^= (1 << 3);
    printf("第3位置1: ");
    print_binary(flags);
    flags ^= (1 << 3);
    printf("第3位取反: ");
    print_binary(flags);

    // 判断是否是2的幂
    int num = 10;
    printf("\n%d是2的幂吗? %s\n", num, (num & (num - 1)) == 0 ? "是" : "否");

    return 0;
}
