#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

struct e {
    int v, next;
};

e edge[100100];
int head[100100], begin[100100], end[100100];
int time, n, idx;

// need to speed up using this technique!
void addedge(int u, int v)
{
    edge[idx].v = v;
    edge[idx].next = head[u];
    head[u] = idx++;
}

void dfs(int cur)
{
    begin[cur] = ++time;
    for (int i = head[cur]; i != -1; i = edge[i].next) {
        dfs(edge[i].v); // curcial!
    }
    end[cur] = time;
}

#define LSB(x) (x & (-x))
int bit[100100];
void add(int x, int val)
{
    while (x <= n) {
        bit[x] += val;
        x += LSB(x);
    }
}

int sum(int x)
{
    int ans = 0;
    while (x > 0) {
        ans += bit[x];
        x -= LSB(x);
    }
    return ans;
}

int main()
{
    scanf("%d", &n);
    time = 0, idx = 0;

    memset(head, -1, sizeof(head));
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addedge(u, v);
    }

    dfs(1);

    int m;
    scanf("%d", &m);
    for (int i = 1; i <= n; i++) {
        add(i, 1);
    }

    for (int i = 0; i < m; i++) {
        char c[10];
        int node;
        scanf("%s %d", c, &node);
        if (c[0] == 'Q') {
            printf("%d\n", sum(end[node]) - sum(begin[node] - 1));
        } else {
            if (sum(begin[node]) - sum(begin[node] - 1) == 0)
                add(begin[node], 1);
            else
                add(begin[node], -1);
        }
    }

    return 0;
}
