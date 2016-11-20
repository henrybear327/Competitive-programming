#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	int mm[n][m];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			scanf("%d", &mm[i][j]);
	
	int ans = 0;

	for(int i = 0; i < n; i++) {
		bool flag = false;
		for(int j = 0; j < m; j++) {
			if(mm[i][j] == 1)
				flag = true;
			if(mm[i][j] != 1 && flag == true)
				ans++;
		}
	}

	for(int i = 0; i < n; i++) {
		bool flag = false;
		for(int j = m - 1; j >= 0; j--) {
			if(mm[i][j] == 1)
				flag = true;
			if(mm[i][j] != 1 && flag == true)
				ans++;
		}
	}
	
	for(int j = 0; j < m; j++) {
		bool flag = false;
		for(int i = 0; i < n; i++) {
			if(mm[i][j] == 1)
				flag = true;
			if(mm[i][j] != 1 && flag == true)
				ans++;
		}
	}
	
	for(int j = 0; j < m; j++) {
		bool flag = false;
		for(int i = n - 1; i >= 0; i--) {
			if(mm[i][j] == 1)
				flag = true;
			if(mm[i][j] != 1 && flag == true)
				ans++;
		}
	}

	printf("%d\n", ans);
	
    return 0;
}
