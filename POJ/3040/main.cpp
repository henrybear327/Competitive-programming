#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
#include <climits>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

int main()
{
	int types, target;
	scanf("%d %d", &types, &target);

	vector<ii> coins;

	ll total = 0;
	for (int i = 0; i < types; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		coins.push_back(ii(a, b));

		total += (ll)a * b;
	}

	sort(coins.begin(), coins.end());
	reverse(coins.begin(), coins.end());

	int res = 0;

	// if the coin value is greater than the target value, just distribute it
	for(int i = 0; i < types; i++) {
		if(coins[i].first >= target) {
			res += coins[i].second;
			coins[i].second = 0;
		}			
	}

	while(true) {
		// greedy: coin change
		
		int used[types];
		memset(used, 0, sizeof(used));
		int remaining = target;
		for(int i = 0; i < types && remaining > 0; i++) {
			if(coins[i].second > 0) {
				used[i] = min(remaining / coins[i].first, coins[i].second); // be aware of the condition
				remaining -= used[i] * coins[i].first;
			}
		}

		// if the remaining > 0, greedy: from small to largest
		if(remaining > 0) {
			for(int i = types - 1; remaining > 0 && i >= 0; i--) {
				if(coins[i].second > 0) {
					int cnt = min( (remaining + coins[i].first - 1) / coins[i].first, coins[i].second - used[i]);
					used[i] += cnt;
					remaining -= cnt * coins[i].first;
				}
			}
		}

		if(remaining > 0)
			break;
		
		/*
		for(int i = 0; i < types; i++) {
			printf("%d%c", used[i], i == types - 1 ? '\n' : ' ');
			coins[i].second -= used[i];
		}
		res++;
		*/
		int mn = INT_MAX;
		for(int i = 0; i < types; i++) {
			if(coins[i].second > 0 && used[i] > 0)
				mn = min(mn, coins[i].second / used[i]);
		}
		for(int i = 0; i < types; i++) {
			if(coins[i].second > 0 && used[i] > 0)
				coins[i].second -= used[i] * mn;
		}
		res += mn;
	}

	printf("%d\n", res);

	return 0;
}
