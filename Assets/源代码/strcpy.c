#include <stdio.h>
#include <string.h> // strcpy 在这个头文件中

char *mycpy(char *dst, const char *src)
{
    int idx = 0;
    do
    {
        dst[idx] = src[idx];
    } while (src[idx++]);
    return dst;
}

int main(void)
{
    char s1[] = "123";
    char s2[] = "abc";
    printf("%s", mycpy(s1, s2));
    printf("%d", sizeof(s1));

    return 0;
}
