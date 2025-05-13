#include <stdio.h>

int main(void)
{
    int ch; // 必须是 int 来接收 getchar() 的返回值并与 EOF 比较

    printf("请输入字符，按 Ctrl+Z (Windows) 或 Ctrl+D (Unix/Linux/macOS) 结束:\n");

    // 循环读取字符，直到 getchar() 返回 EOF
    // (ch = getchar()) != EOF 这个表达式做了两件事：
    // 1. 调用 getchar() 读取一个字符并赋值给 ch
    // 2. 判断 ch 的值是否不等于 EOF
    while ((ch = getchar()) != EOF)
    {
        putchar(ch); // 如果不是 EOF，就输出这个字符
    }

    printf("\n输入结束 (检测到 EOF)。\n"); // 提示用户输入已结束

    return 0;
}