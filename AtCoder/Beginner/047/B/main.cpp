#include <bits/stdc++.h>

using namespace std;

int main()
{
	int w, h, n;
	scanf("%d %d %d", &w, &h, &n);
	
	int m[w][h];
	memset(m, -1, sizeof(m));
	for(int i = 0; i < n; i++) {
		int x, y, a;
		scanf("%d %d %d", &x, &y, &a);

		if(a == 1) {
			for(int i = 0; i < x; i++) 
				for(int j = 0; j < h; j++)
					m[i][j] = 0;
		} else if (a == 2) {
			for(int i = x; i < w; i++) 
				for(int j = 0; j < h; j++)
					m[i][j] = 0;
		} else if(a == 3) {
			for(int i = 0; i < w; i++) 
				for(int j = 0; j < y; j++)
					m[i][j] = 0;
		} else {
			for(int i = 0; i < w; i++) 
				for(int j = y; j < h; j++)
					m[i][j] = 0;
		}
	}
	
	int cnt = 0;
	for(int i = 0; i < w; i++)
		for(int j = 0; j < h; j++)
			if(m[i][j] == -1)
				cnt++;
	printf("%d\n", cnt);

	return 0;
}
