#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
vector< int > g[111][111];

int t;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
	int u, v, w;
	scanf("%d %d %d", &u, &v, &w);

	g[w][u].push_back(v);
	g[w][v].push_back(u);
    }

    int q;
    scanf("%d", &q);
    for(int i = 0; i < q; i++) {
	int u, v;
	scanf("%d %d", &u, &v);

	t = v;
	int ans = 0;
	for(int j = 1; j <= m; j++) {
	    
	}
    }

    return 0;
}
