#include <stdio.h>

int f(void);

// 全局变量 gAll，初始化为 12
int gAll=12;

// 主函数
int main(int argc, char const *argv[])
{
    printf("in %s gAll=%d\n", __func__, gAll);
    f();
    printf("agn in %s gAll=%d\n", __func__, gAll);
    return 0;
}

// 函数 f 的定义
int f(void)
{
    int gAll = 1;
    printf("in %s gAll=%d\n", __func__, gAll);
    gAll += 2;
    printf("agn in %s gAll=%d\n", __func__, gAll);
    return gAll;
}
