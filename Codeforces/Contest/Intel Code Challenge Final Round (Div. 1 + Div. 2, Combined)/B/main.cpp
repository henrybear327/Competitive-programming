#include <bits/stdc++.h>

using namespace std;

int n, m;
int inp[20][20];
bool check()
{
	for(int i = 0; i < n; i++) {
		int mismatch = 0;
		for(int j = 0; j < m; j++) {
			if(inp[i][j] != j + 1)
				mismatch++;
		}
		if(mismatch > 2)
			return false;
	}
	return true;
}

int main()
{
	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			scanf("%d", &inp[i][j]);
	
	// enumerate any two rows
	bool ans = true;
	for(int i = 0; i < m; i++) {
		for(int j = i; j < m; j++) {
			if(i == j) { //no swap
				ans = check();	
			} else {
				for(int x = 0; x < n; x++) {
					int tmp = inp[x][i];
					inp[x][i] = inp[x][j];
					inp[x][j] = tmp;
				}

				ans = check();

				for(int x = 0; x < n; x++) {
					int tmp = inp[x][i];
					inp[x][i] = inp[x][j];
					inp[x][j] = tmp;
				}
			}

			if(ans == true) {
				printf("YES\n");
				return 0;
			}
		}
	}
	printf("NO\n");

	return 0;
}
