#include <bits/stdc++.h>

using namespace std;

int h, w;
bool in(int x, int y)
{
	return (1 <= x && x <= h) && (1 <= y && y <= w);
}

int main()
{
	scanf("%d %d", &h, &w);

	char inp[w + 10];

	int m[h + 1][w + 1];
	memset(m, 0, sizeof(m));
	for(int i = 1; i <= h; i++) {
		scanf("%s", inp + 1);
		for(int j = 1; j <= w; j++) {
			if(inp[j] == '.')
				m[i][j] = 1;
			else
				m[i][j] = 0;
		}
	}
		
	int cnt[h + 1][w + 1];
	memset(cnt, 0, sizeof(cnt));
	const int dx[4] = {0, -1};
	const int dy[4] = {-1, 0};
	for(int i = 1; i <= h; i++) {
		for(int j = 1; j <= w; j++) {
			if(m[i][j] == 0)
				continue;

			for(int k = 0; k < 2; k++) {
				int xx = i + dx[k];
				int yy = j + dy[k];

				if(in(xx, yy) && m[xx][yy] == 1) {
					cnt[i][j]++;
				}
			}
		}
	}


	// 0 1 2 3 
	// 0 1 3 
	for(int i = 1; i <= h; i++) {
		for(int j = 1; j <= w; j++) {
			cnt[i][j] = cnt[i][j - 1] + cnt[i][j];
		}
	}

	int q;
	scanf("%d", &q);

	for(int i = 0; i < q; i++) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		
		int sum = 0;
		for(int j = x1; j <= x2; j++) {
			if(m[j][y1] == 1 && m[j][y1 - 1] == 1) {
				//printf("minus %d %d\n", j, y1);
				sum--;
			}
			sum += cnt[j][y2] - cnt[j][y1 - 1];
		}
		// printf("pre sum = %d\n", sum);

		for(int j = y1; j <= y2; j++) {
			if(m[x1][j] == 1 && m[x1 - 1][j] == 1) {
				// printf("minus %d %d\n", x1, j);
				sum--;
			}
		}

		printf("%d\n", sum);
	}

	return 0;
}
