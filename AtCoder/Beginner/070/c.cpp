#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b)
{
	return a == 0 ? b : gcd(b % a, a);
}

int main()
{
	int n;
	scanf("%d", &n);
	
	ll g = 0;
	ll inp[n];
	for(int i = 0; i < n; i++) {
		scanf("%lld", &inp[i]);

		g = gcd(g, inp[i]);
	}

	ll lcm = inp[0];
	for(int i = 1; i < n; i++) {
		ll gg = gcd(lcm, inp[i]);
		lcm = inp[i] / gg * lcm;
	}

	printf("%lld\n", lcm);

	return 0;
}
