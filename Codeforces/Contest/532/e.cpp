#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

struct Data {
    int to, w, idx;
};

const int N = 200010;
vector<Data> g[N];
bool seen[N];
vector<int> topologicalSort;

bool check(int mid, int n)
{
    topologicalSort.clear();
    memset(seen, false, sizeof(seen));
    int deg[n];
    memset(deg, 0, sizeof(deg));
    for (int i = 0; i < n; i++) {
        for (auto j : g[i]) {
            if (j.w > mid)
                deg[j.to]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (deg[i] == 0)
            q.push(i);
    }
    topologicalSort.reserve(n);
    while (q.size() > 0) {
        int cur = q.front();
        q.pop();
        topologicalSort.push_back(cur);

        for (auto i : g[cur]) {
            if (i.w > mid) {
                deg[i.to]--;
                if (deg[i.to] == 0)
                    q.push(i.to);
            }
        }
    }

    if ((int)topologicalSort.size() != n)
        return false;
    return true;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int l = -1, r = 0;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        u--;
        v--;
        r = max(r, w);
        g[u].push_back({v, w, i});
    }

    // xxxxxvvvvv
    while (r - l > 1) {
        int mid = (l + r) / 2;
        // printf("mid %d\n", mid);
        if (check(mid, n))
            r = mid;
        else
            l = mid;
    }

    // printf("r = %d\n", r);

    check(r, n);
    set<int> ans;
    set<int> prior;
    for (auto i : topologicalSort) {
        prior.insert(i);

        for (auto j : g[i]) {
            if (j.w <= r) {
                if (prior.find(j.to) != prior.end())
                    ans.insert(j.idx);
            }
        }
    }
    printf("%d %d\n", r, (int)ans.size());
    for (auto i : ans)
        printf("%d ", i + 1);

    return 0;
}
