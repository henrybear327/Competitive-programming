#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
	ll n, x;
	scanf("%lld %lld", &n, &x);

	ll dis = 0;
	for(int i = 0; i < n; i++) {
		char inp[100];
		ll cur;
		scanf("%s %lld", inp, &cur);

		if(inp[0] == '+')
			x += cur;
		else {
			if(cur > x)
				dis++;
			else {
				x -= cur;
			}
		}
	}
	printf("%lld %lld\n", x, dis);

	return 0;
}
