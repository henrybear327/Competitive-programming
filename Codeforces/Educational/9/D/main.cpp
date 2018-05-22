#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	int inp[n];
	map<int, int> cnt;
	for(int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);

		inp[i] = tmp;
		if(tmp <= m) // majpr performace improvement
			cnt[tmp]++;
	}

	int res[m + 1];
	memset(res, 0, sizeof(res));
	for(auto i : cnt) {
		if(i.first > m)
			break;
		if(i.second == 0) // major performance improvement
			continue;
		for(int j = i.first; j <= m; j += i.first) {
			res[j] += i.second;
		}
	}		

	int mx = 0, num = -1;
	for(int i = 0; i <= m; i++) { // lcm many not be in cnt!! a * b < m will be fine!
		if(mx < res[i]) {
			num = i;
			mx = res[i];
		}
	}

	if(num == -1) {
		printf("1 0\n");
	} else {
		printf("%d %d\n", num, mx);
		vector<int> ans;
		for(int i = 0; i < n; i++) {
			if(num % inp[i] == 0) {
				ans.push_back(i + 1);
			}
		}
		sort(ans.begin(), ans.end());
		for(auto i : ans)
			printf("%d ", i);
	}

	return 0;
}
