#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<char, ll> ii;

void solve()
{
	int n;
	scanf("%d", &n);

	list<ii> inp;
	for(int i = 0; i < n; i++) {
		char tmp[10];
		ll cnt;
		scanf("%s %lld", tmp, &cnt);

		inp.push_back(ii(tmp[0], cnt));
	}

	/*
	   for(int i = 0; i < n; i++)
	   printf("%c %lld\n", inp[i].first, inp[i].second);
	 */
	
	for(list<ii>::iterator it = inp.begin(); it != inp.end();) {
		bool no_advance = false;
		
		char c = it->first;
		ll cnt = it->second;

		ll remainder = cnt % 3;
		ll newCoin = cnt / 3;

		if(remainder == 0) {
			it = inp.erase(it);	
			no_advance = true;
		} else {
			it->second = remainder;
		}

		if(newCoin > 0) {
			if(inp.rbegin()->first == c) {
				inp.rbegin()->second += newCoin;
			} else {
				inp.push_back(ii(c, newCoin));
			}
		}

		if(it != inp.begin()) {
			list<ii>::iterator it_prev = it;
			it_prev--;

			if(it_prev->first == it->first) {
				it->second += it_prev->second;
				inp.erase(it_prev);
				no_advance = true;
			}
		}
		
		if(no_advance == false)
			it++;
	}
	
	ll ans = 0;
	for(list<ii>::iterator it = inp.begin(); it != inp.end(); it++) 
		ans += it->second;
	printf("%lld\n", ans);
}

int main()
{
	int ncase;
	scanf("%d", &ncase);

	while(ncase--) {
		solve();
	}

	return 0;
}
