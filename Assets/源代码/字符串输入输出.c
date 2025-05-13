#include <stdio.h>
#include <string.h>

int main()
{
    const char *t = "title";
    const char *s;
    s = t;
    printf("%p#%p\n", t, s);

    char word[8] = {0};  // 初始化全0
    char word2[8] = {0}; // 初始化全0
    scanf("%7s", word);
    scanf("%7s", word2);
    printf("%s##%s##\n", word, word2);
    // 检查两个数组的存储情况
    printf("\nword数组：\n");
    for (int i = 0; i < 8; i++)
    {
        printf("下标%d: %c (ASCII: %d)\n", i, word[i], word[i]);
    }

    printf("\nword2数组：\n");
    for (int i = 0; i < 8; i++)
    {
        printf("下标%d: %c (ASCII: %d)\n", i, word2[i], word2[i]);
    }

    return 0;
}
