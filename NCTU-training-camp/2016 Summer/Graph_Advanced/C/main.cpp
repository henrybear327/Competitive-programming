#include <bits/stdc++.h>

using namespace std;
    
#define N 100010
typedef long long ll;
typedef pair<ll, int> ii;

vector<int> ans;
vector< ii > g[N];
ll dist[N];
int par[N];
priority_queue< ii > pq;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < m; i++) {
	int u, v, w;
	scanf("%d %d %d", &u, &v, &w);

	g[u].push_back(ii(v, w));
	g[v].push_back(ii(u, w));
    }

    fill(dist, dist + n + 1, LLONG_MAX);
    dist[1] = 0;

    pq.push(ii(0, 1));

    memset(par, -1, sizeof(par));
    while(pq.empty() == false) {
	ii cur = pq.top();
	int u = cur.second;
	ll cost = -cur.first;
	pq.pop();

	if(cost > dist[u])
	    continue;
	
	for(auto vv : g[u]) {
	    int v = vv.first;
	    ll w = vv.second;
	    if(dist[v] > cost + w) {
		par[v] = u;
		dist[v] = cost + w;
		pq.push(ii(-dist[v], v));
	    }
	}
    }
    /*
    for(int i = 1; i <= n; i++)
	printf("%d\n", dist[i]);
    */

    if(dist[n] == LLONG_MAX) {
	printf("-1");
	return 0;
    }
    
    int trace = par[n];
    ans.push_back(n);
    while(trace != -1) {
	ans.push_back(trace);
	trace = par[trace];
    }
    
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < (int)ans.size(); i++)
	printf("%d ", ans[i]);

    return 0;
}
