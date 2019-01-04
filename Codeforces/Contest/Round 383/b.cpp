#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	int n, x;
	scanf("%d %d", &n, &x);
	
	map<ll, ll> num;
	for(int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);

		num[tmp]++;
	}
	
	ll ans = 0;
	for(auto i : num) {
		ll cur = i.first;
		if(x == 0) {
			ans += (i.second - 1) * (i.second);
			continue;
		}

		ll target = cur ^ x;

		ans += i.second * num[target];
	}

	printf("%lld\n", ans / 2);
		

	return 0;
}
