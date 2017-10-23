#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int loc[5];
ll best;
int ans[5];
int m[5][5];

ll dist(int x, int y, int xx, int yy)
{
	return abs(x - xx) + abs(y - yy);
}

void dfs(int pos, int depth)
{
	if(depth == 5) {
		// cal
		//for(int i = 0; i < 5; i++) {
			//printf("%d%c", loc[i], i == 4 ? '\n' : ' ');
		//}
		
		ll tmp = 0;
		for(int i = 0; i < 25; i++) {
			int x = i / 5;
			int y = i % 5;
			
			ll mn = LLONG_MAX;
			for(int j = 0; j < 5; j++) {
				int xx = loc[j] / 5;
				int yy = loc[j] % 5;
	
				mn = min(mn, (dist(x, y, xx, yy) * m[x][y]));		
			}			
			
			tmp += mn;
		}
		
		//printf("%lld\n", tmp);
		if(tmp < best) {
			memcpy(ans, loc, sizeof(loc));
			best = tmp;
		}
		return;
	}

	for(int i = pos + 1; i < 25; i++) {
		loc[depth] = i;
		dfs(i, depth + 1);
	}
}

void solve()
{
	int n;
	scanf("%d", &n);
	
	memset(m, 0, sizeof(m));
	best = LLONG_MAX;
	for(int i = 0; i < n; i++) {
		int r, c, v;
		scanf("%d %d %d", &r, &c, &v);

		m[r][c] = v;
	}

	dfs(-1, 0);

	for(int i = 0; i < 5; i++) {
		printf("%d%c", ans[i], i == 4 ? '\n' : ' ');
	}
}

int main()
{
	int ncase;
	scanf("%d", &ncase);
	while(ncase--) 
		solve();
	
	return 0;
}
