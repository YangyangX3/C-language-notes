#include <stdio.h>

int main(void)
{
    // printf格式化输出
    printf("%09d\n", 123);
    printf("%-9d\n", 123);

    printf("%9.2f\n", 123.0);
    printf("%*d\n", 6, 123);

    printf("%hhd\n", (char)12345);

    // scanf格式化输入
    int num;
    scanf("%*d%d", &num);
    printf("%d\n", num);

    scanf("%i", &num);
    printf("%d\n", num);

    char str[10];
    scanf(" %[0-9]", str);
    printf("你输入的数字是: %s\n", str);

    // printf和scanf返回值
    int i1 = scanf("%i", &num);
    int i2 = printf("%i\n", num);
    printf("%d:%d\n", i1, i2);
    return 0;
}