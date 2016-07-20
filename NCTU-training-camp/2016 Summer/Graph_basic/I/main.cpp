#include <bits/stdc++.h>

using namespace std;

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

typedef pair<int, int> ii;
int n, m;

struct {
    int par[1000100];
    void init() {
	memset(par, -1, sizeof(par));
    }

    int root(int x) {
	return par[x] < 0 ? x : par[x] = root(par[x]);
    }

    void merge(int x, int y) {
	x = root(x);
	y = root(y);

	if(x == y)
	    return;

	if(par[x] > par[y])
	    swap(x, y);
	par[x] += par[y];
	par[y] = x;
    }
} UFDS;

inline bool bound(int x, int y)
{
    return (0 <= x && x < n) && (0 <= y && y < m);
}

int g[1010][1010], cnt, ox, oy;
void dfs(int x, int y)
{
    if(g[x][y] == -2) {
	UFDS.merge(x * 1000 + y, ox * 1000 + oy);
	cnt++;
	g[x][y] = -3;
	for(int i = 0; i < 4; i++) {
	    int xx = x + dx[i], yy = y + dy[i];
	    if(bound(xx, yy))
		dfs(xx, yy);
	}
    }
}

void mark(int x, int y)
{
    if(g[x][y] == -3) {
	g[x][y] = cnt;
	for(int i = 0; i < 4; i++) {
	    int xx = x + dx[i], yy = y + dy[i];
	    if(bound(xx, yy))
		mark(xx, yy);
	}
    }
}

int main()
{
    UFDS.init();
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++) {
	char inp[2000];
	scanf("%s", inp);
	for(int j = 0; j < m; j++) {
	    if(inp[j] == '*')
		g[i][j] = -1;
	    else
		g[i][j] = -2;
	}
    }

    for(int i = 0; i < n; i++) {
	for(int j = 0; j < m; j++) {
	    if(g[i][j] == -2) {
		cnt = 0;
		ox = i;
		oy = j;
		dfs(i, j);
		mark(i, j);
	    }
	}
    }


    int ans[n][m];
    memset(ans, 0, sizeof(ans));
    for(int i = 0; i < n; i++) {
	for(int j = 0; j < m; j++) {
	    if(g[i][j] != -1)
		continue;
	    
	    vector< pair<int, int> > used;
	    for(int k = 0; k < 4; k++) {
		int xx = i + dx[k], yy = j + dy[k];
		if(bound(xx, yy) && g[xx][yy] != -1) {
		    bool error = false;
		    for(int l = 0; l < (int)used.size(); l++)
			if(UFDS.root(xx * 1000 + yy) == UFDS.root(used[l].first * 1000 + used[l].second)) {
			    error = true;
			    break;
			}
		    if(error)
			continue;
		    used.push_back(ii(xx, yy));
		    ans[i][j] += g[xx][yy];
		}
	    }
	}
    }

    for(int i = 0; i < n; i++) {
	for(int j = 0; j < m; j++) {
	    if(g[i][j] >= 0)
		printf(".");
	    else
		printf("%d", (ans[i][j] + 1) % 10 );
	}
	printf("\n");
    }

    return 0;
}
