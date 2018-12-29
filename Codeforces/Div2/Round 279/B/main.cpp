#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int main()
{
	int n;
	scanf("%d", &n);
	
	map<int, int> next;
	map<int, int> prev;
	map<int, int> deg;
	for(int i = 0; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);

		next[x] = y;
		prev[y] = x;
		if(x != 0)
			deg[x]++;
		if(y != 0)
			deg[y]++;
	}
		
	int ans[n], cur = 0, idx = 1;
	memset(ans, -1, sizeof(ans));
	while(idx < n) {
		ans[idx] = next[cur];
		idx += 2;
		cur = next[cur];
	}
	
	idx = n - 2;
	cur = 0;
	while(idx >= 0) {
		ans[idx] = prev[cur];
		idx -= 2;
		cur = prev[cur];
	}
	
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		if(ans[i] == -1) 
			cnt++;	
	}

	if(cnt != 0) {
		for(auto i : deg) {
			if(i.second == 1) {
				if(prev.find(i.first) == prev.end()) {
					idx = 0;
					cur = i.first;
					while(idx < n) {
						ans[idx] = cur;
						idx += 2;
						cur = next[cur];
					}

					break;
				}
			}
		}
	}

	for(int i : ans)
		printf("%d ", i);

	return 0;
}
