#include <stdio.h>

int main()
{
    // 1. 变量定义与初始化
    int integerVar = 10;        // 定义并初始化一个整型变量
    float floatVar = 3.14f;     // 定义并初始化一个单精度浮点型变量 (注意 'f' 后缀)
    double doubleVar = 2.71828; // 定义并初始化一个双精度浮点型变量
    char charVar = 'A';         // 定义并初始化一个字符型变量

    printf("--- 变量初始值 ---\n");
    printf("整型变量 integerVar: %d\n", integerVar);
    printf("浮点型变量 floatVar: %f\n", floatVar);
    printf("双精度浮点型变量 doubleVar: %lf\n", doubleVar); // 注意 %lf 用于 double
    printf("字符型变量 charVar: %c\n", charVar);
    printf("\n");

    // 2. 变量赋值
    int anotherInteger;         // 定义一个整型变量
    anotherInteger = 25;        // 给变量赋值
    floatVar = floatVar + 1.0f; // 修改浮点型变量的值

    printf("--- 变量赋值后 ---\n");
    printf("另一个整型变量 anotherInteger: %d\n", anotherInteger);
    printf("修改后的 floatVar: %f\n", floatVar);
    printf("\n");

    // 3. 表达式
    int a = 15, b = 4;
    int sum, difference, product, quotient, remainder;
    float float_quotient;

    sum = a + b;                   // 加法表达式
    difference = a - b;            // 减法表达式
    product = a * b;               // 乘法表达式
    quotient = a / b;              // 整型除法表达式 (结果会被截断)
    remainder = a % b;             // 取余表达式
    float_quotient = (float)a / b; // 浮点数除法 (需要强制类型转换)

    printf("--- 表达式计算结果 ---\n");
    printf("%d + %d = %d\n", a, b, sum);
    printf("%d - %d = %d\n", a, b, difference);
    printf("%d * %d = %d\n", a, b, product);
    printf("%d / %d (整型除法) = %d\n", a, b, quotient);
    printf("%d %% %d (取余) = %d\n", a, b, remainder);
    printf("%d / %d (浮点除法) = %f\n", a, b, float_quotient);
    printf("\n");

    // 4. 复合赋值运算符
    int counter = 5;
    printf("--- 复合赋值运算符 ---\n");
    printf("counter 初始值: %d\n", counter);
    counter += 3; // 等价于 counter = counter + 3;
    printf("counter += 3 后: %d\n", counter);
    counter *= 2; // 等价于 counter = counter * 2;
    printf("counter *= 2 后: %d\n", counter);
    printf("\n");

    // 5. 递增和递减运算符
    int i = 1;
    int j = 1;
    printf("--- 递增/递减运算符 ---\n");
    printf("i 初始值: %d\n", i);
    printf("后置递增 i++: %d (表达式的值是递增前的值)\n", i++);
    printf("i 递增后: %d\n", i);

    printf("j 初始值: %d\n", j);
    printf("前置递增 ++j: %d (表达式的值是递增后的值)\n", ++j);
    printf("j 递增后: %d\n", j);
    printf("\n");

    return 0; // 表示程序正常结束
}