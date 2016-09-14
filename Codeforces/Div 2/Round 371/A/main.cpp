#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int main()
{
	ll l1, r1, l2, r2, k;
	scanf("%lld %lld %lld %lld %lld", &l1, &r1, &l2, &r2, &k);

	if(r2 < l1 || l2 > r1)
		printf("0\n");
	else {
		ll ans = 0;

		if(l2 <= l1) {
			ans = min(r1, r2) - l1 + 1;
			if(l1 <= k && k <= min(r1, r2))
				ans--;
		} else if(r2 >= r1) {
			ans = r1 - max(l1, l2) + 1;
			if(max(l1, l2) <= k && k <= r1)
				ans--;
		} else {
			ans = r2 - l2 + 1;
			if(l2 <= k && k <= r2)
				ans--;
		}

		printf("%lld\n", ans);
	}
	
    return 0;
}
