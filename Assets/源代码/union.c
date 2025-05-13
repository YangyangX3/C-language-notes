#include <stdio.h>
#include <string.h> // For strcpy

// 定义一个 union，可以存储整数、浮点数或短字符串
// union 的所有成员共享同一块内存空间
typedef union Data {
    int i;         // 整型成员
    float f;       // 浮点型成员
    char str[20];  // 字符数组，用于存储字符串
} DataValue; // 为 union 定义别名 DataValue

int main() {
    DataValue data; // 创建一个 DataValue 类型的 union 变量

    // 打印 union 的大小，它等于其最大成员的大小
    printf("Size of union DataValue: %zu bytes\n\n", sizeof(DataValue));

    // 1. 存储并访问整数
    data.i = 10;
    printf("Storing integer:\n");
    printf("data.i = %d\n", data.i);
    // 此时访问 f 或 str 会得到不确定的值，因为内存被解释为整数
    // printf("data.f = %f (undefined behavior)\n", data.f);
    // printf("data.str = %s (undefined behavior)\n", data.str);
    printf("--------------------\n");

    // 2. 存储并访问浮点数
    data.f = 220.5f;
    printf("Storing float:\n");
    printf("data.f = %f\n", data.f);
    // 此时访问 i 会得到浮点数 220.5f 在内存中的二进制表示被解释为整数的值
    printf("data.i = %d (float bits interpreted as int)\n", data.i);
    printf("--------------------\n");

    // 3. 存储并访问字符串
    strcpy(data.str, "Hello Union");
    printf("Storing string:\n");
    printf("data.str = %s\n", data.str);
    // 此时访问 i 或 f 会得到字符串 "Hello Union" 的起始字节被解释为整数或浮点数的值
    printf("data.i = %d (string bytes interpreted as int)\n", data.i);
    printf("data.f = %f (string bytes interpreted as float)\n", data.f);
    printf("--------------------\n");

    return 0;
}
