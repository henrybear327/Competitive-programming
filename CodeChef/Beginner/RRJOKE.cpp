#include <bits/stdc++.h>

using namespace std;

int main()
{
	int ncase;
	scanf("%d", &ncase);

	while(ncase--) {
		int n;
		scanf("%d", &n);
		
		vector<int> data[2222];
		for(int i = 1; i <= n; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			
			// runtime error because of the negative number lol
			x += 1000;
			y += 1000;

			data[min(x, y)].push_back(i);
		}

		for(int i = 0; i < 2222; i++)
			sort(data[i].begin(), data[i].end());

		// forward
		int res1 = 0, res2 = 0;
		for(int i = 0; i < 2222; i++) {
			for(int j = 0; j < (int)data[i].size(); j++) {
				res1 ^= data[i][j];
			}
		}

		// backward
		for(int i = 2221; i >= 0; i--) {
			for(int j = 0; j < (int)data[i].size(); j++) {
				res2 ^= data[i][j];
			}
		}

		printf("%d\n", min(res1, res2));
	}

	return 0;
}
