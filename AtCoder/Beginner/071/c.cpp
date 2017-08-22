#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	int n;
	scanf("%d\n", &n);
	map<ll, int> cnt;

	for(int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);

		cnt[num]++;
	}

	ll mx = 0, mx2 = 0;
	for(auto i = cnt.rbegin(); i != cnt.rend(); i++) {
		if(i->second >= 2) {
			if(mx == 0) {
				mx = i->first;

				if(i->second >= 4)
					mx2 = i->first;
			} else {
				if(mx2 == 0) {
					mx2 = i->first;
				}
			}
		}
	}

	printf("%lld\n", mx * mx2);

	return 0;
}
