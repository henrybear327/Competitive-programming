#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
vector<int> g[300010];
int main()
{
    int n;
    scanf("%d", &n);

    int inp[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &inp[i]);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--;
        v--;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    int ans = INT_MAX;
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        cnt[inp[i] + 2]++;
    }

    for (int i = 0; i < n; i++) {
        stack<ii> s;

        // self
        cnt[inp[i]]++;
        cnt[inp[i] + 2]--;
        s.push(ii(inp[i], -1));
        s.push(ii(inp[i] + 2, 1));

        // neighbor
        for (auto v : g[i]) {
            cnt[inp[v] + 1]++;
            cnt[inp[v] + 2]--;
            s.push(ii(inp[v] + 1, -1));
            s.push(ii(inp[v] + 2, 1));
        }

        // update ans
        for (auto i = cnt.rbegin(); i != cnt.rend(); i++) {
            if (i->second != 0) {
                ans = min(ans, i->first);
                break;
            }
        }
        while (s.empty() == false) {
            ii cur = s.top();
            s.pop();

            cnt[cur.first] += cur.second;
        }
    }

    printf("%d\n", ans);

    return 0;
}
