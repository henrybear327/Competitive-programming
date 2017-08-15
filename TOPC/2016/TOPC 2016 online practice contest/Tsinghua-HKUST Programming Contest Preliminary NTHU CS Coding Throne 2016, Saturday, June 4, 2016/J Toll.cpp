#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, ll> ii; 
typedef pair<ll, pair<int, int> > node; // dist, to, used ith station

#define N 1111
vector<ii> g[N];

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while(ncase--) {
	int n, m, t, q;
	scanf("%d %d %d %d", &n, &m, &t, &q);

	for(int i = 0; i <= n; i++)
	    g[i].clear();

	for(int i = 0; i < m; i++) {
	    int u, v, w;
	    scanf("%d %d %d", &u, &v, &w);

	    g[u].push_back(ii(v, w));
	    g[v].push_back(ii(u, w));
	}

	// 1-based
	bool toll[N] = {false};
	for(int i = 0; i < t; i++) { 
	    int tmp;
	    scanf("%d", &tmp);

	    toll[tmp] = true;
	}

	// dijkstra
	priority_queue< node, vector<node>, greater<node> > pq;
	ll d[n + 1][t + 1];
	for(int i = 0; i < n + 1; i++)
	    for(int j = 0; j < t + 1; j++)
		d[i][j] = LLONG_MAX;
	d[1][0] = 0;

	pq.push( node(0, make_pair(1, 0)) );
	while(pq.empty() == false) {
	    node cur = pq.top();
	    pq.pop();

	    ll dist = cur.first;
	    int u = cur.second.first;
	    int usedStation = cur.second.second;

	    // early termination?

	    for(auto i : g[u]) {
		int v = i.first;
		ll w = i.second;

		if(toll[v] == true) {
		    if(usedStation < t && d[v][usedStation + 1] > d[u][usedStation] + w) {
			d[v][usedStation + 1] = d[u][usedStation] + w;
			pq.push(node(d[v][usedStation + 1], make_pair(v, usedStation + 1)));
		    }
		} else {
		    if(d[v][usedStation] > d[u][usedStation] + w) {
			d[v][usedStation] = d[u][usedStation] + w;
			pq.push(node(d[v][usedStation], make_pair(v, usedStation)));
		    }
		}
	    }
	}

	for(int i = 0; i < q; i++) {
	    ll cur;
	    scanf("%lld", &cur);

	    ll mn = LLONG_MAX;
	    for(int j = 0; j <= t; j++) {
		if(d[n][j] == LLONG_MAX)
		    continue;
		mn = min(mn, d[n][j] + cur * j);
	    }
	    printf("%lld%c", mn, i == q - 1 ? '\n' : ' ');
	}
    }

    return 0;
}