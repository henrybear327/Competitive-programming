#include <bits/stdc++.h>

int main()
{
    int cases;
    scanf("%d", &cases);

    int count = 1;
    while (cases--) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        if (a <= 20 && b <= 20 && c <= 20)
            printf("Case %d: good\n", count++);
        else
            printf("Case %d: bad\n", count++);
    }

    return 0;
}
