#include <stdio.h>

int main()
{
    int a, n;
    scanf("%d %d", &a, &n);
    if (a >= 0 && a <= 9 && n >= 1 && n <= 8)
    {
        int sum = 0;
        int t = 0;
        for (int i = 1; i <= n; i++)
        {
            t = t * 10 + a;
            sum += t;
        }
        printf("%d", sum);
    }

    return 0;
}