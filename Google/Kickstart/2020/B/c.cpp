#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;

const char *dir = "NWES";
const int dx[4] = {0, -1, 1, 0};
const int dy[4] = {-1, 0, 0, 1};
ii getDiff(char c)
{
    for (int i = 0; i < 4; i++)
        if (dir[i] == c)
            return ii{dx[i], dy[i]};
    assert(1 == -1);
    return ii{-1, -1};
}
const ll mod = 1e9;

void adjust(int &num)
{
    if (num < 1)
        num = mod;
    if (num == mod + 1)
        num = 1;
}

void solve()
{
    // 2(3(NW)2(W2(EE)W))
    // 3(S2(E))
    stack<int> numStack;
    stack<ii> strStack;

    char inp[2222];
    scanf("%s", inp);

    ii tmp;
    int n = strlen(inp);
    for (int i = 0; i < n; i++) {
        if ('0' <= inp[i] && inp[i] <= '9') {
            strStack.push(tmp);
            numStack.push(inp[i] - '0');
            tmp = ii{0, 0};

            i++; // skip (
        } else if (inp[i] == ')') {
            int rep = numStack.top();
            numStack.pop();
            tmp.first = (tmp.first * rep + 10 * mod) % mod;
            tmp.second = (tmp.second * rep + 10 * mod) % mod;

            tmp.first = tmp.first + strStack.top().first;
            tmp.second = tmp.second + strStack.top().second;
            strStack.pop();
        } else {
            ii t = getDiff(inp[i]);
            tmp.first += t.first;
            tmp.second += t.second;
        }
    }

    tmp.first = (tmp.first + mod) % mod;
    tmp.second = (tmp.second + mod) % mod;

    // printf("%s\n", ans.c_str());
    int x = 1 + tmp.first;
    int y = 1 + tmp.second;

    // printf("%lld %lld\n", tmp.first, tmp.second);

    adjust(x);
    adjust(y);

    printf("%d %d\n", x, y);
}

int main()
{
    int ncase;
    scanf("%d", &ncase);

    for (int i = 1; i <= ncase; i++) {
        printf("Case #%d: ", i);
        solve();
    }

    return 0;
}
