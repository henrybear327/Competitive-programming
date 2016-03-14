#include <bits/stdc++.h>

int main()
{
    int cases, count = 1;
    while (scanf("%d", &cases), cases != 0) {
        int tmp, non_zero = 0, zero = 0;
        for (int i = 0; i < cases; i++) {
            scanf("%d", &tmp);
            if (tmp == 0)
                zero++;
            else
                non_zero++;
        }
        printf("Case %d: %d\n", count++, non_zero - zero);
    }

    return 0;
}
