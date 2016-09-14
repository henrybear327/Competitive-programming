#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
int main()
{
	int ncase;
	scanf("%d", &ncase);

	while(ncase--) {
		int n, m;
		scanf("%d %d", &n, &m);

		int g[n][m];
		long long d[n][m];
		for(int i = 0; i < n; i++) 
			for(int j = 0; j < m; j++) {
				scanf("%d", &g[i][j]);
				d[i][j] = INT_MAX;
			}

		// SPFA
		priority_queue< iii, vector<iii>, greater<iii> > pq;
		
		d[0][0] = g[0][0];
		pq.push(iii(g[0][0], ii(0, 0)));
		while(pq.empty() == false) {
			iii cur = pq.top();
			pq.pop();

			if(cur.first > d[cur.second.first][cur.second.second])
				continue;

			for(int i = 0; i < 4; i++) {
				int xx = cur.second.first + dx[i];
				int yy = cur.second.second + dy[i];

				if(0 <= xx && xx < n && 0 <= yy && yy < m) { // bitch, bound check
					if(cur.first + g[xx][yy] < d[xx][yy]) {
						d[xx][yy] = cur.first + g[xx][yy];
						pq.push(iii(d[xx][yy], ii(xx, yy)));
					}
				}
			}
		}

		printf("%lld\n", d[n - 1][m - 1]);
	}

	return 0;
}
