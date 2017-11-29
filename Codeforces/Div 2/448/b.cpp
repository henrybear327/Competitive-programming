#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	ll n, x, k;
	scanf("%lld %lld %lld", &n, &x, &k);

	ll ans = 0;
	int inp[n];
	map<int, int> cnt;

	for(int i = 0; i < n; i++) {
		scanf("%d", &inp[i]);
		cnt[inp[i]]++;
	}
	sort(inp, inp + n);

	for(int i = 0; i < n; i++) {
		ll left, right;
		if(k > 0) {
			// ok interval
			int rem = inp[i] % x;
			left = inp[i] - rem + (rem == 0 ? x * (k - 1) : x * k);
			right = inp[i] - rem + (rem == 0 ? x * (k - 1) : x * k) + (x - 1); // [l, r]
			// printf("l %d r %d\n", left, right);
		} else {
			// not ok interval
			int rem = inp[i] % x;
			left = inp[i] - rem + 1;
			right = inp[i] - rem + x - 1;
			// printf("l %d r %d\n", left, right);
		}
		
		// add numbers in that interval
		ans += upper_bound(inp + i, inp + n, right) - lower_bound(inp + i, inp + n, left);

		cnt[inp[i]]--;
		// for numbers that has k <= 1, [a, a] will be able to satisfy
		if(k <= 1 && left <= inp[i] && inp[i] <= right)
			ans += cnt[inp[i]];
		// printf("%d\n", ans);

	}
	printf("%lld\n", ans);

	return 0;
}
