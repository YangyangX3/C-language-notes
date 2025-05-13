#include <stdio.h>

// 宏定义是简单的文本替换
#define PI 3.14159
#define FORMAT "%f\n"
#define PI2 2*PI // pi * 2
// 定义宏 PRT，它包含两个 printf 语句
// 宏定义可以包含多行代码，但通常用反斜杠 \ 连接
#define PRT printf("%f ", PI);\
            printf("%f\n", PI2);

// 主函数
int main(int argc, char const *argv[])
{
    // printf(FORMAT, PI2*3.0);

    // 在预处理阶段，PRT 会被替换为后面的两个 printf 语句
    PRT;

    return 0;
}
