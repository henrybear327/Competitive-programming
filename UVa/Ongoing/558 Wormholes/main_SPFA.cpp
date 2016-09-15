
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

const int N = 1111;
vector< ii > g[N];

int n, m;

bool SPFA()
{
    // s->t
    vector<ll> d(n, INT_MAX);
    d[0] = 0;

    queue<int> q;
    vector<bool> inqueue(n, false);
    vector<int> cnt(n, 0);
    q.push(0);
    inqueue[0] = true;
    cnt[0]++;

    while(q.empty() == false) {
        int u = q.front();
        q.pop();
        inqueue[u] = false;

        for(auto i : g[u]) {
            int v = i.first, w = i.second;
            if(d[u] + w < d[v]) {
                d[v] = d[u] + w;
                if(inqueue[v] == false) {
                    q.push(v);
                    inqueue[v] = true;
                    cnt[v]++;

                    if(cnt[v] == n) {
                        // loop!
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while (ncase--) {
        scanf("%d %d", &n, &m);

        for(int i = 0; i < n; i++)
            g[i].clear();

        for (int i = 0; i < m; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);

            g[u].push_back(ii(v, w));
        }

        bool loop = SPFA();

        printf("%s\n", loop ? "possible" : "not possible");
    }

    return 0;
}
