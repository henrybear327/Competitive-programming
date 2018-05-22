#include <bits/stdc++.h>

using namespace std;

int seen[1000100];
vector<int> g[1000100];

vector<int> gg;
void dfs(int u)
{
    if(seen[u] == 1)
	return;
    seen[u] = 1;

    gg.push_back(u);

    for(auto i : g[u]) {
	dfs(i);
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int inp[n];
    for(int i = 0; i < n; i++) {
	scanf("%d", &inp[i]);
    }

    for(int i = 0; i < m; i++) {
	int a, b;
	scanf("%d %d", &a, &b);
	a--;
	b--;

	g[a].push_back(b);
	g[b].push_back(a);
    }

    memset(seen, 0, sizeof(seen));
    for(int i = 0; i < n; i++) {
	if(seen[i] == 0) {
	    gg.clear();
	    dfs(i);

	    sort(gg.begin(), gg.end());
	    vector<int> num;
	    for(int j = 0; j < (int)gg.size(); j++) {
		num.push_back(inp[gg[j]]);
	    }
	    sort(num.begin(), num.end());
	    reverse(num.begin(), num.end());

	    for(int j = 0; j < (int)gg.size(); j++) {
		inp[gg[j]] = num[j];
	    }
	}
    }

    for(int i = 0; i < n; i++) {
	printf("%d ", inp[i]);
    }

    return 0;
}
