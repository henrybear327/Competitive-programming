#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int mod = 1e9 + 7;

int main()
{
	char inp[100010];
	scanf("%s", inp);

	ll ans = 0;
	int cnt = 0;
	for (auto i : inp) {
		if (i == '\0') // WTF
			break;

		if (i == 'a') {
			cnt++;
		} else if (i == 'b') {
			if (ans == 0)
				ans = 1;
			if (cnt > 0)
				ans = (ans * (cnt + 1)) % mod;
			cnt = 0;
		} else {
			continue;
		}
	}

	if (ans == 0)
		ans = 1;
	if (cnt > 0)
		ans = (ans * (cnt + 1)) % mod;

	ans = (ans + mod - 1) % mod;
	printf("%lld\n", ans);

	return 0;
}
