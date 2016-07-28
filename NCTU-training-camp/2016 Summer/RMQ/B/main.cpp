#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
int main()
{
	int n, q;
	scanf("%d %d", &n, &q);
	
	int inp[n];
	for(int i = 0; i < n; i++) 
		scanf("%d", &inp[i]);
	sort(inp, inp + n);
	
	ii cnt[200010]; // start, end
	for(int i = 0; i < q; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--;
		b--;

		cnt[a].first++;
		cnt[b].second++;
	}
	
	int val[n], tot = 0;
	memset(val, 0, sizeof(val));
	for(int i = 0; i < n; i++) {
		tot += cnt[i].first;
		val[i] = tot;
		tot -= cnt[i].second;
	}
	sort(val, val + n);

	ll ans = 0;
	for(int i = 0; i < n; i++)
		ans += (ll)val[i] * inp[i];
	
	printf("%lld\n", ans);

	return 0;
}
