#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
	/*
	 3 7 3
	2 3 0 0 2 0 1
	2 1 3
	1 0 0 0 1 0 0
	0 0 0 0 0 0 1
	1 1 0 0 0 0 0


	2: 2 0 0 0 2 0 0
	1: 0 0 0 0 0 0 1
	3: 2 3 0 0 0 0 0
	   2 3 0 0 2 0 1
	 */

	int n, m, h;
	scanf("%d %d %d", &n, &m, &h);
	int ans[n][m];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) {
			ans[i][j] = 0;
		}
	
	int width[m];
	for(int i = 0; i < m; i++) 
		scanf("%d", &width[i]);
	
	int length[n];
	for(int i = 0; i < n; i++)
		scanf("%d", &length[i]);
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) {
			int num;
			scanf("%d", &num);

			if(num == 0)
				continue;

			ans[i][j] = min(width[j], length[i]);
		}
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			printf("%d%c", ans[i][j], j == m - 1 ? '\n' : ' ');

    return 0;
}
