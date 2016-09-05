#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll M = (ll)1e9 + 7;

inline ll mm (ll num)
{
	return (num + M) % M;
}

int main()
{
	int n;
	scanf("%d", &n);

	for(int i = 0; i < n; i++) {
		/*
		// Solution 1
		ll inp[3];
		for(int i = 0; i < 3; i++) {
		scanf("%lld", &inp[i]);
		}
		sort(inp, inp + 3);

		inp[1] = mm(inp[1] - 1) >= 0 ? mm(inp[1] - 1) : 0;
		inp[2] = mm(inp[2] - 2) >= 0 ? mm(inp[2] - 2) : 0;
		for(int i = 0; i < 3; i++) {
		inp[i] %= M; // WOW
		}

		ll ans = (inp[0] * inp[1]) % M;
		ans = ans * inp[2] % M;

		printf("%lld\n", ans);
		*/

		// solution 2
		ll inp[3];
		for(int i = 0; i < 3; i++) {
			scanf("%lld", &inp[i]);
		}

		ll ans = ((inp[0] % M) * (inp[1] % M)) % M * (inp[2] % M) % M;
		ans = mm(ans - (min(inp[0], inp[1]) % M * (inp[2] % M)));
		ans = mm(ans - (min(inp[0], inp[2]) % M * (inp[1] % M)));
		ans = mm(ans - (min(inp[1], inp[2]) % M * (inp[0] % M)));
		ans = (ans + 2 * (min(inp[0], min(inp[1], inp[2])) % M) % M);

		printf("%lld\n", mm(ans));
	}


	return 0;
}
