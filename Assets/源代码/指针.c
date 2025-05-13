#include <stdio.h>

void f(int *p);
void g(int g);
// void test();

int main()
{
    int i = 3;
    int *t = &i;
    scanf("%d", t);
    printf("i=%d\n", i);
    printf("&1=%p\n", &i);
    f(&i);
    g(i); // 传递 i 的值
    // test();
    return 0;
}

void f(int *p)
{
    printf("p=%p\n", p);
    printf("p=%d\n", *p);
    *p = 5; // 修改指针所指向的值
}

void g(int g)
{
    printf("i=%d\n", g);
}
/*
void test()
{
    int i = 3;
    int *p = &i;
    printf("&i=%d\n", &i);
    printf("&p=%d\n", *p);
}*/