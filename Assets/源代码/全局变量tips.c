#include <stdio.h>

int *f(void);
void g(void); // 函数 g

// 主函数
int main(int argc, char const *argv[])
{
    // 调用 f() 获取局部变量 i 的地址 (危险!)
    int *p = f();
    // 第一次访问 *p (未定义行为)
    printf("*p=%d\n", *p);

    // 调用函数 g
    g();

    // 再次访问 *p (可能已被 g() 覆盖)
    printf("*p=%d\n", *p);

    // 主函数返回 0
    return 0;
}

// 函数 f 的定义
int *f(void)
{
    // 定义局部变量 i
    int i = 12;
    // 返回局部变量地址 (危险!)
    return &i;
}

// 函数 g 的定义
void g(void)
{
    // 定义局部变量 k (可能覆盖 i 的栈空间)
    int k = 24;
    printf("k=%d\n", k);
}
