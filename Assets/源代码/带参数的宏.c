#include <stdio.h>

// 注意：宏定义是文本替换，为了避免运算符优先级问题，参数 x 应该用括号括起来
#define SQUARE(x) ((x) * (x))

// 定义一个带参数的宏 MAX(a, b)，返回 a 和 b 中较大的值
// 同样，参数 a 和 b 用括号括起来
#define MAX(a, b) ((a) > (b) ? (a) : (b))

// 定义一个带参数的宏 PRINT_VAR(var)，打印变量名和值
// 使用 # 运算符可以将宏参数转换为字符串字面量
#define PRINT_VAR(var) printf(#var " = %d\n", var)

int main()
{
    int num1 = 5;
    int num2 = 10;

    // 使用 SQUARE 宏
    int square_of_num1 = SQUARE(num1); // 替换为 ((num1) * (num1))
    printf("Square of %d is %d\n", num1, square_of_num1);

    int square_of_num2_plus_one = SQUARE(num2 + 1);
    printf("Square of (%d + 1) is %d\n", num2, square_of_num2_plus_one);

    // 使用 MAX 宏
    int max_val = MAX(num1, num2);
    printf("Maximum of %d and %d is %d\n", num1, num2, max_val);

    // 使用 PRINT_VAR 宏
    PRINT_VAR(num1);           // 替换为 printf("num1" " = %d\n", num1)
    PRINT_VAR(num2);           // 替换为 printf("num2" " = %d\n", num2)
    PRINT_VAR(square_of_num1); // 替换为 printf("square_of_num1" " = %d\n", square_of_num1)

    return 0;
}
