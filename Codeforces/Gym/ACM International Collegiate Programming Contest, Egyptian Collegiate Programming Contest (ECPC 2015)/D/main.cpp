#include <bits/stdc++.h>
#define N 100100

using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while (ncase--) {
        int n;
        scanf("%d", &n);
        vector<ll> leaf;

        // make graph
        vector<ii> g[N];
        for (int i = 1; i < n; i++) {
            ll p, v;
            scanf("%lld %lld", &p, &v);
            p--;

            g[p].push_back(ii(i, v));
        }

        // bfs from 0
        queue<ii> q;
        q.push(ii(0, 0));

        while (q.empty() == false) {
            ii cur = q.front();
            ll u = cur.first;
            ll t = cur.second;
            q.pop();

            // get
            // the
            // smallest
            // edge
            ll mn = LLONG_MAX;
            for (auto i : g[u]) {
                mn = min(mn, i.second);
            }

            // if
            // leaf
            if (mn == LLONG_MAX)
                leaf.push_back(t);
            else {
                // expand
                for (auto i : g[u]) {
                    if (i.second == mn) {
                        q.push(ii(i.first, i.second + t));
                    } else {
                        q.push(ii(i.first, t + (i.second - mn) * 2 * +*mn));
                    }
                }
            }
        }

        int query;
        scanf("%d", &query);
        sort(leaf.begin(), leaf.end());

        for (int i = 0; i < query; i++) {
            ll now;
            scanf("%lld", &now);

            printf("%d\n",
                   (upper_bound(leaf.begin(), leaf.end(), now) - leaf.begin()));
        }
    }

    return 0;
}
