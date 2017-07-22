// You can absolutely use 2 for-loop
// Or use fenwick tree to achieve nlogn performance

#include <bits/stdc++.h>

using namespace std;

#define LSB(x) (x&(-x))
struct BIT {
	int inp[5555];
	void init() {
		memset(inp, 0, sizeof(inp));
	}

	void add(int pos, int val) {
		while(pos < 5555) {
			inp[pos] += val;
			pos += LSB(pos);
		}
	}

	int sum(int pos) {
		int ret = 0;
		while(pos > 0) {
			ret += inp[pos];
			pos -= LSB(pos);
		}
		return ret;
	}
};

void solve()
{
	int n;
	scanf("%d", &n);

	BIT bit;
	bit.init();

	int ans = 0;
	for(int i = 0; i < n; i++) {
		int cur;
		scanf("%d", &cur);

		ans += bit.sum(cur);
		bit.add(cur, 1);
	}

	printf("%d\n", ans);
}

int main()
{
	int ncase;
	scanf("%d", &ncase);
	
	while(ncase--) {
		solve();
	}
	
	return 0;
}
