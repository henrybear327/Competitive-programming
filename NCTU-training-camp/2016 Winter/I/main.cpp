#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> g[20010];

int dist[20010];
void dfs(int curr)
{
    for(int i = 0; i < (int)g[curr].size(); i++) {
	if(dist[g[curr][i]] == 0) {
	    dist[g[curr][i]] = dist[curr] + 1;
	    dfs(g[curr][i]);
	}
    }
}

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while(ncase--) {
        int n;
        scanf("%d", &n);

        for(int i = 0; i < n - 1; i++) {
            int a, b;
	    scanf("%d %d", &a, &b);

	    g[a].push_back(b);
	    g[b].push_back(a);
        }
	
	memset(dist, 0, sizeof(dist));
	dist[1] = 1;
	dfs(1);

	for(int i = 1; i <= n; i++)
	    printf("%d%c", dist[i], i == n ? '\n' : ' ');
    }
    return 0;
}
