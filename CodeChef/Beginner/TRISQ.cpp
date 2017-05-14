#include <bits/stdc++.h>

using namespace std;

int solve(int n)
{
    if (n <= 3)
        return 0;
    return n / 2 - 1 + solve(n - 2);
}

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while (ncase--) {
        int n;
        scanf("%d", &n);

        printf("%d\n", solve(n));

        /*
        int ans = 0;
        for(int i = n - 2; i >= 2; i -= 2) {
                ans += i / 2;
        }

        printf("%d\n", ans);
        */
    }

    return 0;
}
