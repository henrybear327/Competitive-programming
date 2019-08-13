#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 100010;
vector<int> g[N], g2[N];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--;
        v--;

        g[u].push_back(v);
    }

    int s, t;
    scanf("%d %d", &s, &t);
    s--;
    t--;

    queue<ii> q;
    bool seen[N] = {false};
    q.push(ii(s, 0));
    seen[s] = true;
    int ans = -1;
    while (q.size() > 0) {
        auto cur = q.front();
        q.pop();

        if (cur.first == t) {
            ans = cur.second;
            break;
        }

        for (auto v : g[cur.first]) {
            for (auto v1 : g[v]) {
                if (v1 == v) {
                    if (seen[v1])
                        continue;
                    seen[v1] = true;

                    if (v1 == t) {
                        ans = cur.second + 1;
                        goto done;
                    }

                    q.push(ii(v1, cur.second + 1));

                    continue;
                }

                for (auto v2 : g[v1]) {
                    if (seen[v2])
                        continue;
                    seen[v2] = true;

                    if (v2 == t) {
                        ans = cur.second + 1;
                        goto done;
                    }

                    q.push(ii(v2, cur.second + 1));
                }
            }
        }
    }

done:
    printf("%d\n", ans);

    return 0;
}
