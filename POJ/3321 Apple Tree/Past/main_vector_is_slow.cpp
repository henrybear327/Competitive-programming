#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

vector<int> g[100100];
int begin[100100], end[100100];
int time, n;
void dfs(int cur)
{
    begin[cur] = ++time;
    for (int i = 0; i < (int)g[cur].size(); i++) {
        if (begin[g[cur][i]] == 0) {
            dfs(g[cur][i]);
        }
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
    time = 0;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
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
            if (sum(begin[node]) - sum(begin[node] - 1))
                add(begin[node], -1);
            else
                add(begin[node], 1);
        }
    }

    return 0;
}
