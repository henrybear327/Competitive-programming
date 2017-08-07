#include <bits/stdc++.h>

using namespace std;

int main()
{
	int h, w, n;
	scanf("%d %d %d", &h, &w, &n);
	
	int inp[n];
	for(int i = 0; i < n; i++)
		scanf("%d", &inp[i]);
	
	int ans[h][w];
	int color = 0, cnt = 0, col = 0;
	for(int i = 0; i < h;) {
		if(cnt < inp[color])
			ans[i][col] = color + 1;
		if(i % 2 == 0) {
			col++;
		} else {
			col--;
		}
		
		cnt++;
		if(cnt == inp[color]) {
			cnt = 0;
			color++;
		}
		
		if(col < 0) {
			col = 0;
			i++;
		}
		if(col == w) {
			col = w - 1;
			i++;
		}

	}

	for(int i = 0; i < h; i++)
		for(int j = 0; j < w; j++)
			printf("%d%c", ans[i][j], j == w - 1 ? '\n' : ' ');

	return 0;
}
