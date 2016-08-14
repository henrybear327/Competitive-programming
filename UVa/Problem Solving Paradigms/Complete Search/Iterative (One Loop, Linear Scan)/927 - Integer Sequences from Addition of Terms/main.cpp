#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	int ncase;
	scanf("%d", &ncase);

	while(ncase--) {
		int n;
		scanf("%d", &n);

		ll coeff[n + 1];
		for(int i = 0; i < n + 1; i++)
			scanf("%lld", &coeff[i]);

		ll d;
		scanf("%lld", &d);

		ll k;
		scanf("%lld", &k);
		
		ll prev = 0;
		for(int i = 1; ; i++) {
			if(prev < k && k <= prev + i * d) {
				ll res = coeff[0], x = i;
				for(int j = 1; j < n + 1; j++) {
					res += coeff[j] * x;
					x *= i;
				}
				printf("%lld\n", res);
				break;
			}
			prev += i * d;
		}
	}
	
	return 0;
}
