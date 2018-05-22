#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int main()
{
    ll power[38];
    for(int i = 0; i < 38; i++) {
        power[i] = (1LL << i);
    }

	int n;
	scanf("%d", &n);

	map<ll, ll> inp;
	for(int i = 0; i < n; i++) {
	    int cur;
	    scanf("%d", &cur);

	    inp[cur]++;
	}

	ll ans = 0;
	for(auto i : inp) {
	    ll cur = i.first;
        for(int j = 0; j < 38; j++) {
            ll diff = power[j] - cur;
            if(diff < 0 || inp.find(diff) == inp.end())
                continue;
            if(diff == cur) {
                if(i.second == 1)
                    continue;
                ans += (1 + i.second - 1) * (i.second - 1);
                //printf("aa %lld %lld %lld\n", (1 + i.second - 1) * (i.second - 1) , diff, cur);
                continue;
            }

            auto it = inp.find(diff);
            ans += it->second * i.second;

            //printf("%lld %lld %lld\n", it->second * i.second, diff, cur);
        }
	}

	printf("%lld\n", ans / 2);

    return 0;
}
