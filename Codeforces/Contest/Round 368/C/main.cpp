#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int main()
{
	ll n;
	scanf("%lld", &n);

	if(n == 1 || n == 2) {
		printf("-1\n");
	} else {
		if(n & 1) {
			ll k = (n - 1) / 2;
			ll p = k + 1, q = k;
			printf("%lld %lld\n", 2 * p * q, p * p + q * q); 
		} else {
			n /= 2;
			printf("%lld %lld\n", n * n - 1, n * n + 1);
		}
	}

	return 0;
}
