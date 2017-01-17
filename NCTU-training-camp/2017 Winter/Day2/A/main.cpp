#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int to, cap, rev;
    Edge(int a, int b, int c)
    {
        to = a;
        cap = b;
        rev = c;
    }
};

const int INF = 0x3f3f3f3f;
const int MAX_V = 10000 + 100 + 2 + 100;
vector<vector<Edge>> g(MAX_V);
int level[MAX_V];
int iter[MAX_V];

inline void add_edge(int u, int v, int cap)
{
    g[u].push_back((Edge) {
        v, cap, (int)g[v].size()
    });
    g[v].push_back((Edge) {
        u, 0, (int)g[u].size() - 1
    });
}

void bfs(int s)
{
    memset(level, -1, sizeof(level)); // 用fill
    queue<int> q;

    level[s] = 0;
    q.push(s);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < int(g[v].size()); i++) {
            const Edge &e = g[v][i];
            if (e.cap > 0 && level[e.to] < 0) {
                level[e.to] = level[v] + 1;
                q.push(e.to);
            }
        }
    }
}

int dfs(int v, int t, int f)
{
    if (v == t)
        return f;
    for (int &i = iter[v]; i < int(g[v].size()); i++) { // &很重要
        Edge &e = g[v][i];
        if (e.cap > 0 && level[v] < level[e.to]) {
            int d = dfs(e.to, t, min(f, e.cap));
            if (d > 0) {
                e.cap -= d;
                g[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int max_flow(int s, int t)   // dinic
{
    int flow = 0;
    for (;;) {
        bfs(s);
        if (level[t] < 0)
            return flow;
        memset(iter, 0, sizeof(iter));
        int f;
        while ((f = dfs(s, t, INF)) > 0) {
            flow += f;
        }
    }
}

typedef pair<int, int> ii;

ii inp[111];

int solve(int n)
{
    int l = 0, r = 10001;
    while (r - l > 1) {
        int mid = (l + r) / 2;

        for (int i = 0; i < 10001 + n; i++)
            g[i].clear();

        // s = 0, t = 10001 + n
        for (int i = 0; i < n; i++) {
            for (int j = inp[i].first; j < inp[i].second; j++) {
                add_edge(j, 10001 + i, 1);
            }
        }

        for (int i = 1; i <= 10000; i++)
            add_edge(0, i, 1);

        for (int i = 10001; i < 10001 + n; i++)
            add_edge(i, 10001 + n, mid);

        int mf = max_flow(0, 10001 + n);
        // printf("%d %d %d %d %d\n", l, mid, r, mf, n * mid);
        if (mf >= n * mid) { // okay
            // printf("Ok\n");
            l = mid;
        } else { // can't
            // printf("not okay\n");
            r = mid;
        }
    }

    return l;
}

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);

        inp[i].first = x;
        inp[i].second = y;
    }

    printf("%d\n", solve(n) * n);

    return 0;
}
