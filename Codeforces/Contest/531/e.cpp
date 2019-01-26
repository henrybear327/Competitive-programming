#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const ll MOD = 998244353;

int main()
{
    int n;
    scanf("%d", &n);

    int inp[n];
    map<int, int> lastPos;
    for (int i = 0; i < n; i++) {
        scanf("%d", &inp[i]);
        lastPos[inp[i]] = i;
    }

    set<int> workingWindow;
    ll ans = 1;
    bool ok = false;
    for (int i = 0; i < n; i++) {
        if (ok)
            ans = ans * 2 % MOD;
        ok = false;
        if (lastPos[inp[i]] == i) {
            workingWindow.erase(inp[i]);

            if (workingWindow.size() == 0) {
                ok = true;
            }
        } else {
            workingWindow.insert(inp[i]);
        }
    }

    printf("%lld\n", ans);

    return 0;
}
