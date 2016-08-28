#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int main()
{
	int n, b, d;
	scanf("%d %d %d", &n, &b, &d);

	int sum = 0;
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		int cur;
		scanf("%d", &cur);

		if(cur > b)
			continue;

		sum += cur;
		if(sum > d) {
			sum = 0;
			ans++;
		}
	}

	printf("%lld\n", ans);

	return 0;
}
