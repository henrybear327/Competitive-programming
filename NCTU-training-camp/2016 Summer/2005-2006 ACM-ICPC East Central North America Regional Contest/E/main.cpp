#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef pair< ii, int> iii;

vector< iii > edge;
vector< int > g[22];

int timestamp[22];
int low[22];
int timer;
bool error;
void  hasBridge(int u, int p)
{   
    low[u] = timestamp[u] = timer;
    timer++;

    for(int i = 0; i < (int)g[u].size(); i++) {
	int v = g[u][i];
	if(v == p)
	    continue;
	
	if(timestamp[v] == 0) {
	    hasBridge(v, u);

	    low[u] = min(low[u], low[v]);
	} else {
	    low[u] = min(low[u], timestamp[v]);
	}

	if(timestamp[u] < low[v]) {
	    error = true;
	};
    }
}

int main()
{
    int n, m, ncase = 1;
    while(scanf("%d %d", &n, &m) == 2 && (n || m)) {
	edge.clear();
	for(int i = 0; i < m; i++) {
	    int u, v, w;
	    scanf("%d %d %d", &u, &v, &w);
	    u--;
	    v--;

	    edge.push_back(iii(ii(u, v), w));
	}
	
	int N = 1 << m;
	ll ans = LLONG_MAX;
	for(int i = 1; i < N; i++) {
	    // build graph
	    for(int j = 0; j < n; j++)
		g[j].clear();
	    memset(low, 0, sizeof(low));
	    memset(timestamp, 0, sizeof(timestamp));
	    timer = 1;
	    error = false;

	    ll tmp = 0;
	    int first_node = -1;
	    for(int j = 0; j < m; j++) {
		if( i & (1 << j) ) {
		    int u = edge[j].first.first;
		    if(first_node == -1)
			first_node = u;
		    int v = edge[j].first.second;
		    g[u].push_back(v);
		    g[v].push_back(u);
		    tmp += edge[j].second;
		}
	    }
	    hasBridge( first_node , -1);
	    for(int i = 0; i < n; i++) {
		if(timestamp[i] == 0)
		    error = true;
	    }
	    
	    /*
	    printf("i = %d, error = %d\n", i, error);
	    for(int i = 0; i < n; i++) {
		printf("%d%c", timestamp[i], i == n - 1 ? '\n' : ' ');
	    }
	    */
	    if(error == false) {
		// calculate cost	
		ans = min(ans, tmp);
	    }
	}
	
	if(ans != LLONG_MAX)
	    printf("The minimal cost for test case %d is %lld.\n", ncase++, ans);
	else
	   printf("There is no reliable net possible for test case %d.\n", ncase++);
    }
	
    return 0;
}
