#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

// binary search

int main()
{
    /*
       8 3
       ACACTACG
       v v  v
       11222333
       012344566
       3 7
       2 3
       1 8
    */

    int n, q;
    scanf("%d %d", &n, &q);

    char inp[n + 3];
    scanf("%s", inp);

    vector<int> s;
    for (int i = 0; i + 1 < n; i++)
        if (inp[i] == 'A' && inp[i + 1] == 'C')
            s.push_back(i + 1);

    for (int i = 0; i < q; i++) {
        int l, r;
        scanf("%d %d", &l, &r);

        // 1 3 6
        // [3,7]
        auto lb = lower_bound(s.begin(), s.end(), l);
        auto rb = lower_bound(s.begin(), s.end(), r);
        printf("%ld\n", distance(lb, rb));
    }

    /*
    int dp[n + 1];
    dp[0] = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
    if (i + 1 < n && inp[i] == 'A' && inp[i + 1] == 'C')
        dp[i + 1] = ++cnt, dp[i + 2] = ++cnt, i++;
    else
        dp[i + 1] = cnt;
    }

    for (int i = 0; i <= n; i++) {
    // printf("%d %d\n", i, dp[i]);
    }

    for (int i = 0; i < q; i++) {
    int l, r;
    scanf("%d %d", &l, &r);

    if (inp[l - 1] == 'C')
        l++;
    if (inp[r - 1] == 'A')
        r--;

    if (l <= r)
        printf("%d\n", (dp[r] - dp[l - 1]) / 2);
    else
        printf("0\n");
    }
    */

    return 0;
}
