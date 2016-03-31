#include <bits/stdc++.h>
//LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

typedef long long int ll;

using namespace std;

vector<int> g[100100];
int n, m;
bool visited[100100];
int cntv, cntn;
void dfs(int u)
{
    visited[u] = true;
    cntv += (int)g[u].size();
    cntn++;

    for(int i = 0; i < (int)g[u].size(); i++) {
	if(visited[g[u][i]] == false) {
	    visited[g[u][i]] = true;
	    dfs(g[u][i]);
	}
    }
}

int main()
{
    scanf("%d %d", &n, &m);

    for(int i = 0; i < m; i++) {
	int a, b;
	scanf("%d %d", &a, &b);

	g[a].push_back(b);
	g[b].push_back(a);
    }

    memset(visited, false, sizeof(visited));
    int ans = 0;
    for(int i = 1; i <= n; i++) {
	cntv = cntn = 0;
	if(visited[i] == false) {
	    dfs(i);
	    cntv /= 2;
	    if(cntv <= cntn - 1)
		ans++;
	}
    }
    
    printf("%d\n", ans);
	
    return 0;
}
