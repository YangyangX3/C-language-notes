#include <stdio.h>

// 匿名结构体无法重复使用
// 普通结构体可以重复使用，其余无异
// typedef的结构体代码简洁，并且可以向前定义
// typedef的匿名结构更加简洁并且可以重复使用，只是不能向前定义，因为结构体无名
// 匿名结构体仅影响代码书写形式，运行时与普通结构体无差异

typedef struct date
{
    int day;
    int month;
    int year;
} DATE;

typedef struct
{
    int day;
    int month;
    int year;
} DATE;

int main(int argc, const char *argv[])
{

    DATE today;
    today.day = 1;
    today.month = 1;
    today.year = 2023;
    return 0;
}