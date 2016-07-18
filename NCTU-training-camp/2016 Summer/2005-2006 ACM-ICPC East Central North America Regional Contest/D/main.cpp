#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

const int dxk[8] = {1, 2, 1, 2, -1, -2, -1, -2};
const int dyk[8] = {2, 1, -2, -1, 2, 1, -2, -1};

const int dxq[8] = {0, 0, 1, 1, 1, -1, -1, -1};
const int dyq[8] = {1, -1, 1, 0, -1, -1, 0, 1};

int n, m;
bool bound(int x, int y)
{
    return (1 <= x && x <= n) && (1 <= y && y <= m);
}

typedef pair<int, int> ii;

int main()
{
    int ncase = 1;
    while(scanf("%d %d", &n, &m) == 2  && (n || m)) {
	int t[n + 1][m + 1];
	memset(t, -1, sizeof(t));

	int cnt;
	// q 1
	scanf("%d", &cnt);
	
	vector< ii > qpos;
	for(int i = 0; i < cnt; i++) {
	    int x, y;
	    scanf("%d %d", &x, &y);
    
	    qpos.push_back(ii(x, y));
	}
	// k 2
	vector< ii > kpos;
	scanf("%d", &cnt);
	for(int i = 0; i < cnt; i++) {
	    int x, y;
	    scanf("%d %d", &x, &y);

	    kpos.push_back(ii(x, y));

	    t[x][y] = 2;
	}
	// p 3
	scanf("%d", &cnt);
	for(int i = 0; i < cnt; i++) {
	    int x, y;
	    scanf("%d %d", &x, &y);
	    
	    t[x][y] = 3;
	}

	// run q
	for(int k = 0; k < (int)qpos.size(); k++) {
	    int x = qpos[k].first, y = qpos[k].second;
	    t[x][y] = 1;
	    for(int i = 0; i < 8; i++) {
		int xx = x + dxq[i], yy = y + dyq[i];
		while (bound(xx, yy) && (t[xx][yy] == -1 || t[xx][yy] == 11) ) {
		    t[xx][yy] = 11;
		    xx = xx + dxq[i];
		    yy = yy + dyq[i];
		}
	    }
	}
	// run k
	for(int k = 0; k < (int)kpos.size(); k++) {
	    int x = kpos[k].first, y = kpos[k].second;
	    for(int i = 0; i < 8; i++) {
		int xx = x + dxk[i], yy = y + dyk[i];
		if(bound(xx, yy) && (t[xx][yy] == -1 || t[xx][yy] == 11) )
		    t[xx][yy] = 11;
	    }
	}
	
	int ans = 0;
	for(int i = 1; i <= n; i++)
	    for(int j = 1; j <= m; j++)
		if(t[i][j] == -1)
		    ans++;
	printf("Board %d has %d safe squares.\n", ncase++, ans);
    }
	
    return 0;
}
