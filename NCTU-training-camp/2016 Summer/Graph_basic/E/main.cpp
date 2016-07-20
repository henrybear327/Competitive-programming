#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    
    ii cost[1111];
    int orig[1111];
    for(int i = 0; i < n; i++) {
	int c;
	scanf("%d", &c);
	cost[i] = ii(c, i);
	orig[i] = c;
    }

    vector<int> g[1111];
    for(int i = 0; i < m; i++) {
	int u, v;
	scanf("%d %d", &u, &v);

	u--;
	v--;
	g[u].push_back(v);
	g[v].push_back(u);
    }

    sort(cost, cost + n);
    bool removed[n];
    memset(removed, false, sizeof(removed));
    ll ans = 0;
    for(int i = n - 1; i >= 0; i--) {
	removed[cost[i].second] = true;
	for(auto j : g[cost[i].second]) {
	    if(removed[j] == false)
		ans += orig[j];
	}
    }

    printf("%lld\n", ans);

    return 0;
}
