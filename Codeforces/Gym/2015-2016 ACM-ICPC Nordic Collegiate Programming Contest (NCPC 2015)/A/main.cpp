#include <bits/stdc++.h>
//LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

typedef long long int ll;

using namespace std;

vector<int> g[100010];
int deg[100010];

struct UFDS {
    int par[100010];
    vector<int> m[100010];
    void init(int n) {
	memset(par, -1, sizeof(par));
	for(int i = 0; i < n; i++) {
	    m[i].clear();
	    m[i].push_back(i);
	}
    }
    int root(int x) {
	return par[x] < 0 ? x : par[x] = root(par[x]);
    }
    void merge(int x, int y) {
	x = root(x);
	y = root(y);

	if(x != y) {
	    if(par[x] > par[y])
		swap(x, y);
	    par[x] += par[y];
	    m[x].insert(m[x].end(), m[y].begin(), m[y].end());  
	    m[y].clear();

	    par[y] = x;
	}
    }
};

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    if(k == 0) {
	printf("2\n");	
	return 0;
    }

    UFDS uf;
    uf.init(n);
    for(int i = 0; i < n; i++) {
	g[i].clear();
	deg[i] = 0;
    }

    for(int i = 0; i < k; i++) {
	int u, v;
	scanf("%d %d", &u, &v);

	g[u].push_back(v);
	g[v].push_back(u);
	deg[u]++;
	deg[v]++;
	uf.merge(u, v);
    }

    vector<int> ans;
    for(int i = 0; i < n; i++) {
	if(uf.par[i] < 0) {
	    // tree center
	    queue<int> q[2];
	    int useq = 0;
	    for(int j = 0; j < (int)uf.m[i].size(); j++) {
		// add leaf to queue
		int v = uf.m[i][j];
		if(deg[v] == 1) {
		    q[useq].push(v);
		}
	    }

	    int change = 0;
	    int level[100010] = {0};
	    while(q[useq].empty() == false) {
		int cur = q[useq].front();
		q[useq].pop();

		for(int j = 0; j < (int)g[cur].size(); j++) {
		    int v = g[cur][j];
		    deg[v]--;
		    if(deg[v] == 1) {
			level[v] = level[cur] + 1;
			change = max(change, level[v]);
			q[useq ^ 1].push(v);
		    }
		}

		if(q[useq].size() == 0) {
		    useq ^= 1;
		    if(q[useq].size() == 0) {
			break;
		    }
		}
	    }
	    int cntCenter = 0;
	    for(int u : uf.m[i]) {
		//printf("u %d\n", u);
		if(level[u] == change)
		    cntCenter++;
	    }
	    //printf("%d\n", cntCenter);
	    ans.push_back(2 * change + cntCenter - 1);
	}
    }
    sort(ans.begin(), ans.end());
    reverse(ans.begin(), ans.end());
    /*
       for(int i = 0; i < (int)ans.size(); i++)
       printf("a %d\n", ans[i]);
    */
    if(ans.size() == 1)
	printf("%d\n", ans[0]);
    else {
	int mx = ans[0];
	mx = max(mx, (ans[0] + 1) / 2 + (ans[1] + 1) / 2 + 1);
	if(ans.size() > 2)
	    mx = max(mx, (ans[1] + 1) / 2 + (ans[2] + 1) / 2 + 2);
	printf("%d\n", mx);
    }

    return 0;
}
