#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	
	int inp[n][6];
	set<int> ok;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 6; j++) {
			scanf("%d", &inp[i][j]);
			ok.insert(inp[i][j]);
		}
	}

	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			for(int x = 0; x < 6; x++) {
				for(int y = 0; y < 6; y++) {
					int num = inp[i][x] * 10 + inp[j][y];
					ok.insert(num);
					num = inp[i][x] + inp[j][y] * 10;
					ok.insert(num);
				}
			}

			for(int k = j + 1; k < n; k++) {
				for(int x = 0; x < 6; x++) {
					for(int y = 0; y < 6; y++) {
						for(int z = 0; z < 6; z++) {
							// ABC
							int num = inp[i][x] * 100 + inp[j][y] * 10 + inp[k][z];
							ok.insert(num);
							// ACB
							num = inp[i][x] * 100 + inp[j][y] + inp[k][z] * 10;
							ok.insert(num);

							// BAC
							num = inp[i][x] * 10 + inp[j][y] * 100 + inp[k][z];
							ok.insert(num);

							// BCA
							num = inp[i][x] + inp[j][y] * 100 + inp[k][z] * 10;
							ok.insert(num);

							// CAB
							num = inp[i][x] * 10 + inp[j][y] + inp[k][z] * 100;
							ok.insert(num);

							// CBA
							num = inp[i][x] + inp[j][y] * 10 + inp[k][z] * 100;
							ok.insert(num);
						}
					}
				}
			}
		}
	}

	int range[1001] = {0};
	for(auto i : ok) {
		range[i] = 1;
	}
		
	int ans = 0;
	for(int i = 1; i <= 1000; i++) {
		if(range[i] == 0)
			break;
		ans = i;
	}

	printf("%d\n", ans);

	return 0;
}
