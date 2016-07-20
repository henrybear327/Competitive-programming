#include <bits/stdc++.h>

using namespace std;

#define N 100010
int ind[N], outd[N];

int seen[N];
vector<int> g[N];

void dfs(int u)
{
    if(seen[u])
	return;
    seen[u] = 1;
    for(auto v : g[u])
	dfs(v);
}

int main()
{
    int T;
    scanf("%d", &T);

    while (T--) {
        int n, m;
        scanf("%d %d", &n, &m);

        memset(ind, 0, sizeof(ind));
        memset(outd, 0, sizeof(outd));

	for(int i = 0; i < N; i++)
	    g[i].clear();
	
	int used[n + 1];
	memset(used, 0, sizeof(used));
        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);

	    used[u] = used[v] = 1;
            if (u == v)
                continue;
            ind[v]++;
            outd[u]++;
	    g[u].push_back(v);
        }

        int same = 0, onlyin = 0, onlyout = 0, outidx;
        for (int i = 1; i <= n; i++) {
	    if(used[i] == 0)
		continue;
            if (ind[i] == outd[i])
                same++;
            if (ind[i] - outd[i] == 1) {
                onlyin++;
            }
            if (outd[i] - ind[i] == 1) {
                onlyout++;
                outidx = i;
            }
        }
	
	memset(seen, 0, sizeof(seen));
	dfs(1);
	
	int gcnt = 1;
	int nn = 0;
	for(int i = 1; i <= n; i++) {
	    if(used[i] == 1)
		nn++;
	    if(used[i] == 1 && seen[i] == 0)
		gcnt = 0;
	}
        if (gcnt == 1 && onlyin == 1 && outidx == 1 && onlyout == 1 && same == nn - 2) // euler path
            printf("Mu\n"); 
        else if (gcnt == 1 && same == nn) // euler cycle
            printf("Su\n");
        else
            printf("Kan\n");
    }

    return 0;
}
