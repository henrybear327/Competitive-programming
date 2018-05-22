#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
	ll n;
	scanf("%lld", &n);
	
	for(int i = 30; i >= 1; i--) {
		ll tmp = ((1LL << i) - 1) * (1LL << (i - 1));
		if(tmp <= n && n % tmp == 0) {
			printf("%lld\n", tmp);
			break;
		}
	}

	return 0;
}
