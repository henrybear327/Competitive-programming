#include <bits/stdc++.h>

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    if (n % 2 == 0) {
        if (m <= n / 2)
            printf("%d\n", m + 1);
        else
            printf("%d\n", m - 1);
    } else {
        if (n == 1)
            printf("1\n");
        else if (m < (n / 2 + 1))
            printf("%d\n", m + 1);
        else
            printf("%d\n", m - 1);
    }

    return 0;
}
