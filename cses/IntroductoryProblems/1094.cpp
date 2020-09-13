#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    int prev = -1;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int tmp;
        scanf("%d", &tmp);

        if (i == 0)
            prev = tmp;
        else {
            if (tmp < prev)
                ans += (prev - tmp) * 1LL; // long long required
            else
                prev = tmp; // we only update when the tmp >= prev :) 
        }
    }

    printf("%lld\n", ans);

    return 0;
}
