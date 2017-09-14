#include <bits/stdc++.h>

int main()
{
    int n;
    scanf("%d", &n);

    int inp[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &inp[i]);

    bool ok = (n & 1) && (inp[0] & 1) && (inp[n - 1] & 1);
    printf("%s\n", ok ? "Yes" : "No");

    return 0;
}
