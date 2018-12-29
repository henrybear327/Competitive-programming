#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	map<int, int> occur;
	int from[n];
	memset(from, -1, sizeof(from));
	int mx[n];
	fill(mx, mx + n, 1);
	int id = 0;
	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);

		if (occur.count(num - 1) > 0) {
			from[i] = occur[num - 1];
			mx[i] = mx[occur[num - 1]] + 1;

			if (mx[id] < mx[i]) {
				id = i;
			}
		}
		occur[num] = i;
	}

	vector<int> ans;
	while (id != -1) {
		ans.push_back(id + 1);
		id = from[id];
	}
	reverse(ans.begin(), ans.end());
	printf("%d\n", (int)ans.size());
	for (auto i : ans)
		printf("%d ", i);

	return 0;
}
