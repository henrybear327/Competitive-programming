#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;


// union find won't work if you have an interval completely inside another interval
vector<int> g[111];

void dfs(int u, bool seen[])
{
    if(seen[u])
	return;
    seen[u] = true;

    for(auto v : g[u])
	dfs(v, seen);
}

int main()
{
    int n;
    scanf("%d", &n);
    
    ii interval[111];
    int idx = 1;
    for(int i = 0; i < n; i++) {
	int x, c, d;
	scanf("%d %d %d", &x, &c, &d);

	if(x == 1) {
	    for(int j = 1; j < idx; j++) {
		int a = interval[j].first, b = interval[j].second;
		if( (c < a && a < d) || (c < b && b < d) ) {
		    g[j].push_back(idx);
		}
		if( (a < c && c < b) || (a < d && d < b) ) {
		    g[idx].push_back(j);
		}
	    }
	    interval[idx++] = ii(c, d);
	} else {
	    bool seen[111] = {false};
	    dfs(c, seen);
	    if(seen[d])
		printf("YES\n");
	    else
		printf("NO\n");
	}
    }

    return 0;
}
