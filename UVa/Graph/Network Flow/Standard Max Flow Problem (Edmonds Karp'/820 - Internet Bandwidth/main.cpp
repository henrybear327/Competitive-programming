#include <bits/stdc++.h>

using namespace std;

#define MAX 110
struct edge {
    int to, cap, rev;
};

vector<edge> G[MAX];
int level[MAX];
int iter[MAX];

void add_edge(int from, int to, int cap)
{
    // forward
    G[from].push_back((edge) {
        to, cap, (int)G[to].size()
    });
    // backward
    G[to].push_back((edge) {
        from, 0, (int)G[from].size() - 1
    });
}

void BFS(int s)
{
    memset(level, -1, sizeof(level));
    queue<int> que;
    level[s] = 0;
    que.push(s);
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (int i = 0; i < (int)G[v].size(); i++) {
            edge &e = G[v][i];
            if (e.cap > 0 && level[e.to] < 0) {
                level[e.to] = level[v] + 1;
                que.push(e.to);
            }
        }
    }
}

int dfs(int v, int t, int f)
{
    if (v == t)
        return f;
    for (int &i = iter[v]; i < (int)G[v].size(); i++) {
        edge &e = G[v][i];
        if (e.cap > 0 && level[v] < level[e.to]) {
            int d = dfs(e.to, t, min(f, e.cap));
            if (d > 0) {
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int max_flow(int s, int t)
{
    int flow = 0;
    for (;;) {
        BFS(s);
        if (level[t] < 0)
            return flow;
        memset(iter, 0, sizeof(iter));
        int f;
        int INF = (int)1e9;
        while ((f = dfs(s, t, INF)) > 0) {
            flow += f;
        }
    }
}

int main()
{
    int node, index = 1;
    while(scanf("%d", &node) == 1 && node) {
        for(int i = 0; i < MAX; i++)
            G[i].clear();

        int s, t, E;
        scanf("%d %d %d", &s, &t, &E);

        for(int i = 0; i < E; i++) {
            int from, to, weight;
            scanf("%d %d %d", &from, &to, &weight);
            add_edge(from, to, weight);
            add_edge(to, from, weight);
        }

        printf("Network %d\nThe bandwidth is %d.\n\n",index++, max_flow(s,t));
    }

    return 0;
}


