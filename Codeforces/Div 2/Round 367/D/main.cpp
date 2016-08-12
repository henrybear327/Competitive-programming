#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int main()
{
	int n;
	scanf("%d", &n);
	
	unordered_map<int,int> cnt;
	set<int> num;
	cnt[0]++;
	num.insert(0);
	for(int j = 0; j < n; j++) {
		char inp[100];
		int x;
		scanf("%s %d", inp, &x);

		if(inp[0] == '+') {
			cnt[x]++;
			if(cnt[x] == 1)
				num.insert(x);
		} else if(inp[0] == '-') {
			cnt[x]--;
			if(cnt[x] == 0)
				num.erase(x);
		} else {
			auto it = num.rbegin();
			int z = 32 - __builtin_clz(*it);
			// int z1 = 32 - __builtin_clz(x);
			
			int l = 0, r = 0; // [l, r]
			bool first = true;
			for(int i = z - 1; i >=0; i--) {
				if(first) {
					if(x & (1 << i)) {
						// l = x ^ (1 << i);
						l = 0;
						r = (1 << i) - 1;
					} else {
						l = (1 << i);
						r = (1LL << (i + 1)) - 1;
					}
					
					auto lb = num.lower_bound(l);
					if(lb != num.end()) {
						if(*lb <= r) {
							first = false;
						}
					}
				} else {
					int tl = l, tr = r;
					if(x & (1 << i)) {
						tr &= ~(1 << i);
					} else {
						tl |= (1 << i);
					}

					auto lb = num.lower_bound(tl);
					if(lb != num.end()) {
						if(*lb <= tr) {
							l = tl;
							r = tr;
						}
					}
				}
				
				//printf("mid %lld %lld\n", l, r);
			}
			//printf("final %lld %lld\n", l, r);

			auto lb = num.lower_bound(l);

			int ans = x ^ (*lb);
			/*
			for(auto i = lb; i != ub; i++) {
				ans = max((int)ans, x ^ (i->first));
			}
			*/

			printf("%d\n", ans);
		}
	}		
	
    return 0;
}
