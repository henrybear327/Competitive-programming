#include <bits/stdc++.h>

using namespace std;

const char* orientation = "NSLO"; //NSEW

int main()
{
	int n, m, s;
	while(scanf("%d %d %d", &n, &m, &s) == 3 && (n || m || s)) {
		char g[n][m + 10];
		int sx, sy, facing = -1;
		for(int i = 0; i < n; i++) {
			scanf("%s", g[i]);
			for(int j = 0; j < m && facing == -1; j++) {
				for(int k = 0; k < 4; k++) {
					if(g[i][j] == orientation[k]) {
						sx = i;
						sy = j;
						if(k == 0)
							facing = 0;
						if(k == 1)
							facing = 2;
						if(k == 2)
							facing = 1;
						if(k == 3)
							facing = 3;
						break;
					}
				}
			}
		}

		char cmd[50010];
		scanf("%s", cmd);

		// NESW
		// 0123 <- facing
		int dx[4] = {-1, 0, 1, 0};
		int dy[4] = {0, 1, 0, -1};

		int ans = 0;
		for(int i = 0; i < s; i++) {
			if(cmd[i] == 'D') 
				facing = (facing + 1) % 4;
			else if(cmd[i] == 'E')
				facing = (facing - 1 + 4) % 4;
			else {
				int xx = sx + dx[facing];
				int yy = sy + dy[facing];
				// inbound
				if( (0 <= xx && xx < n) && (0 <= yy && yy < m) ) {
					// not pillar
					if(g[xx][yy] != '#') {
						// move and collect
						if(g[xx][yy] == '*') {
							ans++;
							g[xx][yy] = '.';
						}
						sx = xx;
						sy = yy;
					}
				}
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}
