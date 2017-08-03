#include <bits/stdc++.h>

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < 10; i++) {
        if ((1 << i) > n) {
            printf("%d\n", (1 << (i - 1)));
            break;
        }
    }

    return 0;
}