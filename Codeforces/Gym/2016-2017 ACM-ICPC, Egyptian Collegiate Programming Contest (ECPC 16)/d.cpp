lude<bits / stdc++.h>

using namespace std;

typedef long long ll;
ll dp[30][30];
ll C(ll a, ll b)
{
    if (dp[a][b] != -1)
        return dp[a][b];
    ll ans = 1;
    for (int i = 1; i <= b; i++) {
        ans = ans * (a - i + 1);
        ans = ans / i;
    }
    return dp[a][b] = ans;
}

void solve()
{
    int n, m;
    scanf("%d %d", &n, &m);

    printf("%lld\n", C(n, m));
}

int main()
{
    freopen("popcorn.in", "r", stdin);
    int ncase;
    scanf("%d", &ncase);
    memset(dp, -1, sizeof(dp));
    while (ncase--)
        solve();

    return 0;
}
