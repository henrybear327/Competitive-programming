#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, bool> ii;

vector<int> g[100010];
int leftCnt;
int rightCnt;

bool nodeType[100010];
void dfs(int u, bool isRight, int p)
{
    if (isRight == false) {
        leftCnt++;
        nodeType[u] = false;
    } else {
        rightCnt++;
        nodeType[u] = true;
    }

    for (auto v : g[u]) {
        if (v == p)
            continue;
        dfs(v, !isRight, u);
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--;
        v--;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    leftCnt = rightCnt = 0;
    dfs(0, false, -1);

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (nodeType[i] == false) {
            int tmp = rightCnt - g[i].size();
            if (tmp > 0)
                ans += tmp;
        }
    }
    printf("%lld\n", ans);

    return 0;
}
