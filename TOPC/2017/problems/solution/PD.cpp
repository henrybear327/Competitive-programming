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
		Iter cur = arr.begin();
		do {
			if (cur != arr.begin()) {
				auto pre = prev(cur);
				if (pre->first == cur->first) {
					cur->second += pre->second;
					arr.erase(pre);
				}
			}
			if (cur->second >= 3) {
				if (next(cur) == arr.end() || cur->first != arr.back().first)
					arr.emplace_back(cur->first, 0);
				arr.back().second += cur->second / 3;
				cur->second %= 3;
				if (cur->second == 0)
					cur = arr.erase(cur);
			} else cur++;
		} while (cur != arr.end());
		long long ans = 0;
		for(cur = arr.begin(); cur != arr.end(); cur++) {
			ans += cur->second;
#ifdef DEBUG
			printf("%c %d\n", cur->first, cur->second);
#endif
		}
		//printf("%lu\n", arr.size());
		printf("%lld\n", ans);
	}
	return 0;
}

