#include <bits/stdc++.h>
//LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

typedef long long int ll;

using namespace std;

int n;
bool visited[500010];
int leaf[500010];
vector<int> g[500010];
void dfs(int curr)
{
    vector<int> child;
    for(int i = 0; i < (int)g[curr].size(); i++) {
	if(visited[g[curr][i]] == false) {
	    visited[g[curr][i]] = true;
	    child.push_back(g[curr][i]);
	    leaf[curr]++;
	    dfs(g[curr][i]);
	}
    }

    if(leaf[curr] == 0)
	return;
    else {
	if(child.size() == 1)
	    leaf[curr] = leaf[child[0]] + 1;
	else
	    for(int i = 0; i < (int)child.size(); i++) {
		if(leaf[child[i]] != 0)
		    leaf[curr] += leaf[child[i]] - 1;
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

    memset(visited, false, sizeof(visited));
    memset(leaf, 0, sizeof(leaf));
    visited[1] = true; // bitch~
    dfs(1);

    /*
       for(int i = 1; i <= n; i++)
       printf("%d%c", leaf[i], i == n ? '\n' : ' '); 
    */

    int ans = 0;
    for(int i = 0; i < (int)g[1].size(); i++) 
	ans = max(ans, leaf[g[1][i]] + 1);
    printf("%d\n",ans);

    return 0;
}
