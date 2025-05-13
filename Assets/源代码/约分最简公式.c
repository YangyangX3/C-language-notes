#include <stdio.h>

int main()
{
    int fz, fm;
    scanf("%d/%d", &fz, &fm);
    int t, z = fz, m = fm;
    while (m > 0)
    {
        t = z;
        z = m;
        m = t % m;
    }
    printf("%d/%d", fz / z, fm / z);
    return 0;
}
