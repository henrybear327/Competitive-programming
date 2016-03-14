#include <bits/stdc++.h>

using namespace std;

int n;
int leaf_depth[500010], cnt;
vector<int> g[500010];

/*
Unnecessary memset causing TLE (TLE vs 390 ms!!)
*/

void dfs(int u, int parent = 1, int depth = 1) 
{
    // u -> v
    // just know who's the parent is enough, because it's a tree, and every node has only one parent
    // root 1 is at depth 0
    if(g[u].size() == 1) { //leaf
	leaf_depth[cnt++] = depth;
	return;
    }

    for(auto v : g[u]) {
	if(v != parent) {
	    dfs(v, u, depth + 1);
	}
    }
}

int main()
{
    scanf("%d", &n);

    for(int i = 0; i < n - 1; i++) {
	int a, b;
	scanf("%d %d", &a, &b);

	g[a].push_back(b);
	g[b].push_back(a);
    }
    
    int ans = INT_MIN;
    for(auto i : g[1]) {
	cnt = 0;
	// memset(leaf_depth, 0, sizeof(leaf_depth));

	dfs(i);

	sort(leaf_depth, leaf_depth + cnt); // based on the assumption 1, lift the shallow nodes first

	int a[cnt + 1];
	// memset(a, 0, sizeof(a));
	a[0] = 0;
	for(int j = 1; j < cnt + 1; j++) {
	    // the time needed to move up to root, is the max of (node depth, previous node time + 1)
	    a[j] = max(leaf_depth[j - 1], a[j - 1] + 1); 
	    ans = max(ans, a[j]);
	}
    }

    printf("%d\n", ans);

    return 0;
}
