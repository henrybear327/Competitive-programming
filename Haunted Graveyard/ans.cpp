#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <deque>
using namespace std;
int g[35][35];
int hole[35][35][3];
int W, H, G, E;
int spfa(int &negcycle) {
	deque<int> X, Y;
	int x, y, tx, ty;
	int i, j, k;
	int dx[] = {0,0,1,-1};
	int dy[] = {1,-1,0,0};
	int inq[35][35] = {}, inqc[35][35] = {};
	int dist[35][35];
	int node = 0;
	for(i = 0; i < W; i++)
		for(j = 0; j < H; j++)
			node += g[i][j] == 0;
	memset(dist, 63, sizeof(dist));
	X.push_front(0), Y.push_front(0);
	dist[0][0] = 0, inqc[0][0]++;
	while(!X.empty()) {
		x = X.front(), X.pop_front();
		y = Y.front(), Y.pop_front();
		inq[x][y] = 0;
		if(x == W-1 && y == H-1)
			continue;
		if(hole[x][y][0] != -1) {//haunted hole
			tx = hole[x][y][0], ty = hole[x][y][1];
			if(dist[tx][ty] > dist[x][y] + hole[x][y][2]) {
				dist[tx][ty] = dist[x][y] + hole[x][y][2];
				if(inq[tx][ty] == 0)  {
					if(!X.empty() && dist[X.front()][Y.front()] > dist[tx][ty])
						X.push_front(tx), Y.push_front(ty);
					else
						X.push_back(tx), Y.push_back(ty);
					inq[tx][ty] = 1;
					if(++inqc[tx][ty] > node) {
						negcycle = 1;
						return 0; // negative cycle
					}
				}
			}
			continue;//important
		}
		for(i = 0; i < 4; i++) {
			tx = x+dx[i], ty = y+dy[i];
			if(tx < 0 || ty < 0 || tx >= W || ty >= H)
				continue;
			if(g[tx][ty])	continue;//gravestone
			if(dist[tx][ty] > dist[x][y]+1) {
				dist[tx][ty] = dist[x][y]+1;
				if(inq[tx][ty] == 0)  {
					if(!X.empty() && dist[X.front()][Y.front()] > dist[tx][ty])
						X.push_front(tx), Y.push_front(ty);
					else
						X.push_back(tx), Y.push_back(ty);
					inq[tx][ty] = 1;
					if(++inqc[tx][ty] > node) {
						negcycle = 1;
						return 0; // negative cycle
					}
				}
			}
		}
	}
	return dist[W-1][H-1];
}
int main() {
	int i, j, k, x, y;
	int sx, sy, ex, ey, t;
	while(scanf("%d %d", &W, &H) == 2 && W+H) {
		memset(g, 0, sizeof(g));
		memset(hole, -1, sizeof(hole));
		scanf("%d", &G);
		for(i = 0; i < G; i++) {
			scanf("%d %d", &x, &y);
			g[x][y] = 1;
		}
		scanf("%d", &E);
		for(i = 0; i < E; i++) {
			scanf("%d %d %d %d %d", &sx, &sy, &ex, &ey, &t);
			hole[sx][sy][0] = ex;
			hole[sx][sy][1] = ey;
			hole[sx][sy][2] = t;
		}
		int negcycle = 0;
		int ret = spfa(negcycle);
		if(negcycle)
			puts("Never");
		else if(ret == 0x3f3f3f3f)
			puts("Impossible");
		else
			printf("%d\n", ret);
	}
	return 0;
} 