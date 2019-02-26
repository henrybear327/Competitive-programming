#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 100010;
vector<int> g[N];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        g[u].push_back(v);
        g[v].push_back(u);
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    bool seen[N] = {false};
    pq.push(1);
    seen[1] = true;
    vector<int> ans;
    while(pq.size() > 0) {
        int u = pq.top();
        pq.pop();

        ans.push_back(u);
        for(auto v : g[u]) {
            if(seen[v])
                continue;
            pq.push(v);
            seen[v] = true;
        }
    }

    for(auto i : ans)
        printf("%d ", i);

    return 0;
}
