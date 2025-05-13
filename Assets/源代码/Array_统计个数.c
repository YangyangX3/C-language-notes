#include <stdio.h>

int main()
{
    // const int size = 10;
    int number[10] = {0};
    int x;

    scanf("%d", &x);
    while (x != -1)
    {
        if (x >= 0 && x <= 9)
        {
            number[x]++;
        }
        scanf("%d", &x);
    }
    for (int i = 0; i < sizeof(number) / sizeof(number[0]); i++)
    {
        printf("%d:%d\n", i, number[i]);
    }
    return 0;
}