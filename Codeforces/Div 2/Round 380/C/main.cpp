#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

#define CAR_N 200010
ll n, k, s, t;
int gas[CAR_N];
bool check(int val)
{
	int time = 0;
	for(int i = 1; i < k + 2; i++) {
		int diff = gas[i] - gas[i - 1];
		if(diff > val)
			return false;
		int left = 0, right = diff + 1;
		while(right - left > 1) {
			int mid = (left + right) / 2;
			
			int a = mid;
			int b = diff - mid;
			if(2 * a + b <= val)
				left = mid;
			else
				right = mid;
		}
		
		time += (left + 2 * (diff - left));
	}
	
	return time <= t;
}

int main()
{
	scanf("%lld %lld %lld %lld", &n, &k, &s, &t);
	
	ii car[CAR_N];
	for(int i = 0; i < n; i++)
	scanf("%d %d", &car[i].first, &car[i].second);  // price, capacity
	
	gas[0] = 0;
	for(int i = 1; i <= k; i++) {
		int pos;
		scanf("%d", &pos);
		gas[i] = pos;
	}
	gas[k + 1] = s;
		
	sort(gas, gas + k + 2);

	ll left = -1, right = 1000000001;
	while(right - left > 1) {
		ll mid = (left + right) / 2;

		if(check(mid))
			right = mid;
		else
			left = mid;
	}

	// find the min price with tank >= right
	int ans = INT_MAX;
	for(int i = 0; i < n; i++) {
		if(car[i].second >= right)
			ans = min(ans, car[i].first);
	}
	if(ans == INT_MAX)
		printf("-1\n");
	else
		printf("%d\n", ans);
	
    return 0;
}
