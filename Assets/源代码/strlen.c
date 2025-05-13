#include <stdio.h>
#include <string.h>

size_t mylen(const char *s)
{

    int index = 0;
    while (s[index] != 0)
    {
        index++;
    }
    return index;
}

int main(int argc, char const *argv[])
{
    char line[] = "Hello";
    printf("strlen=%lu\n", mylen(line));
    printf("sizeof=%lu\n", sizeof(line));
}