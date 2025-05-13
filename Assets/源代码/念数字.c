#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int nixu = 0;
    if (n < 0)
    {
        printf("fu ");
        n = -n;
    }
    int t = n;
    while (t != 0)
    {
        int d = t % 10;
        t /= 10;
        nixu = nixu * 10 + d;
    }
    while (nixu != 0)
    {
        int d = nixu % 10;
        nixu /= 10;

        switch (d)
        {
        case 0:
            printf("ling");
            break;
        case 1:
            printf("yi");
            break;
        case 2:
            printf("er");
            break;
        case 3:
            printf("san");
            break;
        case 4:
            printf("si");
            break;
        case 5:
            printf("wu");
            break;
        case 6:
            printf("liu");
            break;
        case 7:
            printf("qi");
            break;
        case 8:
            printf("ba");
            break;
        case 9:
            printf("jiu");
            break;
        default:
            break;
        }
        if (nixu != 0)
        {
            printf(" ");
        }
    }
    return 0;
}