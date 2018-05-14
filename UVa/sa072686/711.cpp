// bounded knapsack
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
	int inp[6];
	int ncase = 1;
	while (1) {
		int totalValue = 0;
		for (int i = 0; i < 6; i++) {
			scanf("%d", &inp[i]);
			totalValue += inp[i] * (i + 1);
		}

		if (totalValue == 0)
			break;

		printf("Collection #%d:\n", ncase++);
		if (totalValue % 2 == 1)
			printf("Can't be divided.\n");
		else {
			vector<int> val;
			for (int i = 0; i < 6; i++) {
				for (int j = 0;; j++) {
					int diff = inp[i] - (1 << j);
					if (diff > 0) {
						val.push_back((1 << j) * (i + 1));
					} else {
						if (inp[i] != 0)
							val.push_back(inp[i] * (i + 1));
						break;
					}
					inp[i] -= (1 << j);
				}
			}

			bool dp[totalValue / 2 + 1];
			memset(dp, false, sizeof(dp));

			dp[0] = 1;
			for (auto v : val)
				for (int i = totalValue / 2; i >= 0; i--)
					if (i + v <= totalValue / 2 && dp[i] == true)
						dp[i + v] = true;

			if (dp[totalValue / 2])
				printf("Can be divided.\n");
			else
				printf("Can't be divided.\n");
		}
		printf("\n");
	}

	return 0;
}
