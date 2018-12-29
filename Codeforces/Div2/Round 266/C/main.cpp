#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int main()
{
	int n;
	scanf("%d", &n);

	ll inp[n], sum = 0;
	for(int i = 0; i < n; i++) {
		scanf("%lld", &inp[i]);
		sum += inp[i];
	}

	if(sum % 3 != 0) {
		printf("0\n");
		return 0;
	}

	ll pre[n + 1];
	pre[0] = 0;
	for(int i = 1; i <= n; i++)
		pre[i] = pre[i - 1] + inp[i - 1];
	
	ll ans = 0;
	/*
	if(sum == 0) {
		ll cnt = 0;
		for(int i = 1; i <= n; i++) {
			if(pre[i] == 0)
				cnt++;
		}
		ans += (cnt - 1) * (cnt - 2) / 2;
		ans = ans < 0 ? 0 : ans;
	} else {
		ll cnt3 = 0, cnt36 = 0;
		for(int i = 1; i <= n; i++) {
			if(pre[i] == sum / 3)
				cnt3++;
			else if(pre[i] == sum / 3 * 2) 
				cnt36 += cnt3;
		}
		ans = cnt36;
	}
	*/
	ll cnt3 = 0, cnt36 = 0;
	for(int i = 1; i < n; i++) {
		if(pre[i] == sum / 3 * 2) 
			cnt36 += cnt3;
		if(pre[i] == sum / 3)
			cnt3++;
	}
	ans = cnt36;


	printf("%lld\n", ans);

	return 0;
}
