#include <stdio.h>

int main()
{
    int x;
    int sum = 0;
    int cnt = 0;
    int number[100];
    scanf("%d", &x);
    while (x != -1)
    {
        number[cnt] = x;
        sum += x;
        cnt++;
        scanf("%d", &x);
    }
    if (cnt > 0)
    {
        printf("%d %.1f\n", sum, (float)sum / cnt);
        for (int i = 0; i < cnt; i++)
        {
            if (number[i] > sum / cnt)
            {
                printf("%d ", number[i]);
            }
        }
    }

    return 0;
}