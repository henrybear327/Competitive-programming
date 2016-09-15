#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

const int N = 1111;

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while (ncase--) {
        vector<pair<ii, int>> edge;

        int n, m;
        scanf("%d %d", &n, &m);

        for (int i = 0; i < m; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);

            edge.push_back(make_pair(ii(u, v), w));
        }

        // Bellman ford
        ll d[n];
        fill(d, d + n, INT_MAX);
        d[0] = 0;
        bool loop = false;
        for (int i = 0; i <= n; i++) {
            bool hasChange = false;

            for (int j = 0; j < (int)edge.size(); j++) {
                int u = edge[j].first.first, v = edge[j].first.second,
                    w = edge[j].second;
                if (d[u] + w < d[v]) {
                    hasChange = true;
                    d[v] = d[u] + w;
                }
            }

            if (hasChange == true && i == n)
                loop = true;
            else if (hasChange == false)
                break;
        }

        printf("%s\n", loop ? "possible" : "not possible");
    }

    return 0;
}
