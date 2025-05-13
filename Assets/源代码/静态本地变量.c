#include <stdio.h>

// 函数 f 的声明
int f(void);

// 定义全局变量 gAll，初始化为 12
int gAll = 12;

// 主函数
int main(int argc, char const *argv[])
{
    f();
    return 0;
}

// 函数 f 的定义
int f(void)
{
    int k = 0;
    static int all = 1;
    printf("&gAll=%p\n", &gAll);
    printf("&all =%p\n", &all);
    printf("&k   =%p\n", &k);

    printf("in %s all=%d\n", __func__, all);
    all += 2;
    printf("agn in %s all=%d\n", __func__, all);
    return all;
}
