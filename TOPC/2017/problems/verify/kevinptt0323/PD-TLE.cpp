#include <bits/stdc++.h>
//#define DEBUG
using namespace std;

list<pair<char, int>> arr;
typedef list<pair<char, int>>::iterator Iter;

int main() {
	int T, n;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		arr.clear();
		char s[5];
		int num;
		for(int i=0; i<n; i++) {
			scanf("%s %d", s, &num);
			arr.emplace_back(s[0], num);
		}
		while (1) {
			bool change = false;
			for(Iter cur = arr.begin(); cur != arr.end(); ) {
				Iter nxt = next(cur);
				if (nxt != arr.end() && cur->first == nxt->first) {
					nxt->second += cur->second;
					cur = arr.erase(cur);
				} else cur++;
			}
			for(Iter cur = arr.begin(); cur != arr.end(); cur++) {
				if (cur->second>=3) {
					arr.emplace_back(cur->first, cur->second/3);
					cur->second %= 3;
					if (cur->second==0)
						cur = arr.erase(cur);
					change = true;
					break;
				}
			}
			if (!change) break;
		}
		long long ans = 0;
		for(Iter cur = arr.begin(); cur != arr.end(); cur++) {
			ans += cur->second;
#ifdef DEBUG
			printf("%c %d\n", cur->first, cur->second);
#endif
		}
		printf("%lld\n", ans);
	}
	return 0;
}


