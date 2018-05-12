#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

tuple<int, string> dfs(int l, int r, ii inp[], int n,
                       vector<vector<tuple<int, string>>> &dp) // [l, r]
{
    if (l == r)
        return make_tuple(0, "A" + to_string(l + 1));
    if (r - l == 1)
        return make_tuple(inp[l].first * inp[l].second * inp[r].second,
                          "(A" + to_string(l + 1) + " x A" + to_string(r + 1) +
                          ")");
    if (get<0>(dp[l][r]) != -1)
        return make_tuple(get<0>(dp[l][r]), get<1>(dp[l][r]));

    int mn = INT_MAX;
    string retString = "";
    for (int i = l; i < r; i++) {
        tuple<int, string> left = dfs(l, i, inp, n, dp);
        tuple<int, string> right = dfs(i + 1, r, inp, n, dp);
        int current = inp[l].first * inp[i].second * inp[r].second;

        int res = get<0>(left) + current + get<0>(right);
        if (mn > res) {
            mn = res;
            retString = "(" + get<1>(left) + " x " + get<1>(right) + ")";
        }
    }

    return dp[l][r] = tie(mn, retString);
}

string solve(int n)
{
    ii inp[n];
    for (int i = 0; i < n; i++)
        cin >> inp[i].first >> inp[i].second;

    vector<vector<tuple<int, string>>> dp(
        n, vector<tuple<int, string>>(n, make_tuple(-1, "")));

    auto ret = dfs(0, n - 1, inp, n, dp);
    // cout << get<0>(ret) << " " << get<1>(ret) << endl;
    return get<1>(ret);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    for (int i = 1; cin >> n; i++) {
        if (n == 0)
            break;
        cout << "Case " << i << ": " << solve(n) << endl;
    }

    return 0;
}
