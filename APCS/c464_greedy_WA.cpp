#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Data {
	int w, f;
};

int main()
{
	int n;
	scanf("%d", &n);
	
	Data data[n];
	ll weight = 0;
	
	for(int i = 0; i < n; i++) {
		scanf("%d", &data[i].w);
		weight += data[i].w;
	}

	unordered_map<ll, multiset<ll, greater<ll>>> fcnt;
	for(int i = 0; i < n; i++) {
		scanf("%d", &data[i].f);
		fcnt[data[i].f].insert(data[i].w);
	}
	
	ll ans = 0;
	for(int r = 0; r < n - 1; r++) {
		ll mn = LLONG_MAX;
		auto who = fcnt.end();
		for(auto it = fcnt.begin(); it != fcnt.end(); it++) { // for every frequency
			ll mx_weight = *(it->second).begin(); // find max weight

			ll rw = weight - mx_weight; // get remaining weight
			if(mn > rw * it->first) {
				mn = rw * it->first;
				who = it;
			} else if(mn == rw * it->first) {
				if(mx_weight < *(who->second).begin()) { // when tie, pick the one with bigger weight less freq
					who = it;	
				}
			}
		}
		
		printf("weight %lld freq %lld\n", *who->second.begin(), who->first);
		ans += who->first * (weight - *(who->second).begin());
		weight -= *who->second.begin();
		who->second.erase(who->second.begin());
		if(who->second.size() == 0)
			fcnt.erase(who);
		printf("weight %lld ans %lld\n", weight, ans);
	}
	printf("%lld\n", ans);
	
	return 0;
}
