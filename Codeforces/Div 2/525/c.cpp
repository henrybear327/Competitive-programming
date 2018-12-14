#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

struct Data {
	int op;
	int i;
	int x;
};

int main()
{
	int n;
	scanf("%d", &n);

	int inp[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &inp[i]);

	vector<Data> ans;
	int acc = 0;
	for (int i = n - 1; i >= 0; i--) {
		int target = i;
		int cur = (acc + inp[i]) % n;

		if (cur <= target) {
			int add = target - cur;
			acc += add;
			ans.push_back({1, i + 1, add});
		} else {
			int add = n - cur + target;
			acc += add;
			ans.push_back({1, i + 1, add});
		}
	}
	ans.push_back({2, n, n});

	printf("%d\n", (int)ans.size());
	for (auto i : ans)
		printf("%d %d %d\n", i.op, i.i, i.x);

	return 0;
}
