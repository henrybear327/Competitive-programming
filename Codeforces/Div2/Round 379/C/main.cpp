#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> ii;

bool cmp(ii a, ii b)
{
	return a.second < b.second;
}

int main()
{
	ll n, m, k;
	scanf("%lld %lld %lld", &n , &m, &k);

	ll x, s;
	scanf("%lld %lld", &x, &s);

	ii one[m], two[k];
	for(int i = 0; i < m; i++)
		scanf("%lld", &one[i].first);
	for(int i = 0; i < m; i++)
		scanf("%lld", &one[i].second);

	sort(one, one + m, cmp);
	ii dp[m];
	dp[0] = ii(one[0].second, one[0].first);
	for(int i = 1; i < m; i++) {
		if(dp[i - 1].second < one[i].first)
			dp[i] = ii(one[i].second, dp[i - 1].second);
		else
			dp[i] = ii(one[i].second, one[i].first);
	}

	for(int i = 0; i < k; i++)
		scanf("%lld", &two[i].first);
	for(int i = 0; i < k; i++)
		scanf("%lld", &two[i].second);
	
	ll answer = n * x;
	for(int i = 0; i < k; i++) {
		ll nn = n - two[i].first;
		ll ss = s - two[i].second;

		if(ss < 0)
			continue;

		if(nn <= 0) {
			answer = 0;
			break;
		}
		
		int left = -1, right = m;
		while(right - left > 1) {
			int mid = (left + right) / 2;
			if(dp[mid].first <= ss)
				left = mid;
			else
				right = mid;
		}
	
		if(left == -1) {
			answer = min(answer, nn * x);
		} else {
			answer = min(answer, nn * dp[left].second);
		}
	}

	for(int i = 0; i < m; i++) {
		if(dp[i].first <= s) {
			answer = min(answer, dp[i].second * n);
		}
	}

	printf("%lld\n", answer);

    return 0;
}
