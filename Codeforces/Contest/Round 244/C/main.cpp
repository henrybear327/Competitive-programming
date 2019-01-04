#include <bits/stdc++.h>
// LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

using namespace std;

stack<int> s;
vector<int> g[100000 + 100];
int n, m;
void dfs(int curr, int visited[])
{
    visited[curr] = 1;
    for (int i = 0; i < (int)g[curr].size(); i++) {
        if (visited[g[curr][i]] == 0) {
            dfs(g[curr][i], visited);
        }
    }
    s.push(curr);
}

vector<int> rg[100000 + 100];
void reverse()
{
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < (int)g[i].size(); j++) {
            rg[g[i][j]].push_back(i);
        }
    }
}

int cnt = 0, tmp_ans;
long long int ans = 0, method = 0, method_tmp = 0;
int cost[100000 + 100];
void rdfs(int curr, int visited[])
{
    if (tmp_ans > cost[curr]) {
        tmp_ans = cost[curr];
        method_tmp = 1;
    } else if (tmp_ans == cost[curr])
        method_tmp++;

    visited[curr] = 1;
    for (int i = 0; i < (int)rg[curr].size(); i++) {
        if (visited[rg[curr][i]] == 0) {
            rdfs(rg[curr][i], visited);
        }
    }
}

int main()
{
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &cost[i]);
    }

    scanf("%d", &m);

    // construct graph
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        g[a].push_back(b);
    }

    // dfs (normal)
    int visited[n + 1];
    memset(visited, 0, sizeof(visited));
    for (int i = 1; i <= n; i++)
        if (visited[i] == 0)
            dfs(i, visited);

    // reverse
    reverse();

    // do dfs(reverse)
    memset(visited, 0, sizeof(visited));
    ans = 0;
    while (!s.empty()) {
        int curr = s.top();
        s.pop();

        if (visited[curr] == 0) {
            cnt++;
            tmp_ans = INT_MAX;
            method_tmp = 0;
            rdfs(curr, visited);
            if (method == 0)
                method = method_tmp;
            else
                method =
                    ((method_tmp % 1000000007) * (method % 1000000007)) % 1000000007;
            ans += tmp_ans;
        }
    }

    printf("%lld %lld\n", ans, method);

    return 0;
}
