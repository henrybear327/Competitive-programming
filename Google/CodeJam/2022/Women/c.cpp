#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int TC;
    cin >> TC;
    for (int tc = 1; tc <= TC; tc++) {
        int n;
        cin >> n;

        vector<vector<pair<int, int>>> G(n);
        vector<int> deg(n);
        long long sum = 0;
        for (int i = 0; i < n - 1; i++) {
            int u, v, c;
            cin >> u >> v >> c;
            u--;
            v--;
            G[u].push_back({v, c});
            G[v].push_back({u, c});
            deg[u]++;
            deg[v]++;
            sum += c;
        }

        long long ans = LLONG_MAX;
        function<void(int, int, long long)> DFS = [&](int u, int p,
        long long cost) {
            if (p != -1 && deg[u] == 1)
                ans = min(ans, cost + (sum - cost) * 2);
            for (auto &[v, c] : G[u]) {
                if (v != p) {
                    DFS(v, u, cost + c);
                }
            }
        };

        for (int u = 0; u < n; u++) {
            if (deg[u] == 1)
                DFS(u, -1, 0);
        }

        cout << "Case #" << tc << ": " << ans << '\n';
    }

    return 0;
}
