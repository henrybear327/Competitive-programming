#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
    return a == 0 ? b : gcd(b % a, a);
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    int inp[n];
    int g = 0;
    int mx = INT_MIN;
    for (int i = 0; i < n; i++) {
        scanf("%d", &inp[i]);
        g = gcd(g, inp[i]);
        mx = max(mx, inp[i]);
    }

    if (g == 1)
        if (k <= mx)
            printf("POSSIBLE\n");
        else
            printf("IMPOSSIBLE\n");
    else {
        if (k <= mx && k % g == 0)
            printf("POSSIBLE\n");
        else
            printf("IMPOSSIBLE\n");
    }
}