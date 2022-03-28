#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

struct Import {
    int m, l, e;
};

int solve()
{
    int d, n, u;
    scanf("%d %d %d", &d, &n, &u);

    Import leaves[d];
    int idx = 0;
    for (int i = 0; i < d; i++) {
        scanf("%d %d %d", &leaves[i].m, &leaves[i].l, &leaves[i].e);
    }

    int ans = 0;
    priority_queue<ii, vector<ii>, greater<ii>> pq; // <expire time, which>
    int orders[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &orders[i]);
    for (int i = 0; i < n; i++) {
        int o = orders[i];

        // pop outdated
        while (pq.size() > 0) {
            if (pq.top().first <= o) {
                pq.pop();
            } else {
                break;
            }
        }

        // add import if possible
        while (idx < d) {
            if (leaves[idx].m <= o) {
                if (leaves[idx].m + leaves[idx].e > o) {
                    pq.push(ii{leaves[idx].m + leaves[idx].e, idx});
                }

                idx++;
            } else {
                break;
            }
        }

        // try to use leaves
        bool ok = false;
        int acc = 0;
        while (pq.size() > 0) {
            if (leaves[pq.top().second].l >= (u - acc)) {
                leaves[pq.top().second].l -= (u - acc);
                acc += (u - acc);

                if (leaves[pq.top().second].l == 0)
                    pq.pop();
            } else {
                acc += leaves[pq.top().second].l;
                pq.pop();
            }

            if (acc >= u) {
                ans++;
                ok = true;
                break;
            }
        }
        if (ok == false) {
            break;
        }
    }

    return ans;
}

int main()
{
    int ncase;
    scanf("%d", &ncase);

    for (int i = 1; i <= ncase; i++) {
        printf("Case #%d: %d\n", i, solve());
    }

    return 0;
}
