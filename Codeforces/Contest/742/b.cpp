#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int dp[300010];

int solve()
{
    int a, b;
    scanf("%d %d", &a, &b);

    int ans = a;
    int val = dp[a - 1];

    if (val == b)
        return ans;
    else {
        int offset = val ^ b;
        if (offset == a) {
            ans += 2;
        } else {
            ans++;
        }

        return ans;
    }
}

int main()
{
    /*
    MEX = a [0, a) -> a numbers
    XOR = b

    1 ^ 2 = 01 ^ 10 = 11 = 3
    1 ^ 3 = 01 ^ 11 = 10 = 2
    */

    dp[0] = 0;
    for (int i = 1; i < 300001; i++)
        dp[i] = dp[i - 1] ^ i;

    int ncase;
    scanf("%d", &ncase);
    while (ncase--)
        printf("%d\n", solve());

    return 0;
}
