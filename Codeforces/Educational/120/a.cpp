#include <bits/stdc++.h>

using namespace std;

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while (ncase--) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        if (a + b == c || a + c == b || b + c == a)
            printf("YES\n");
        else if ((a == b && c % 2 == 0 && c >= 2) ||
                 (a == c && b % 2 == 0 && b >= 2) ||
                 (b == c && a % 2 == 0 && a >= 2))
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
