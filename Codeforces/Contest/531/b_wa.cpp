#include <bits/stdc++.h>

using namespace std;

/*
If we assign color by giving out one color for every number
then 
8 5
1 2 3 3 3 3 4 5
you get WA! 
*/

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	int ans[n];
	memset(ans, -1, sizeof(ans));
	vector<int> inp[5555];
	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);

		inp[num].push_back(i);
	}

	// fill in the color, disregarding the color limitation
	stack<int> s;
	int c = 1, cnt = 0;
	for (c = 1; c <= n; c++) {
		int orig = cnt;
		for (int j = 1; j <= 5000; j++) {
			if (inp[j].size() > 0) {
				cnt++;
				s.push(inp[j].back());
				ans[inp[j].back()] = c;
				inp[j].pop_back();
			}
		}

		if (orig == cnt) {
			c--; // rollback since no op!
			break;
		}
	}

	if (c == k + 1) {       // done
	} else if (c < k + 1) { // color not used
		while (c < k + 1) {
			int cur = s.top();
			s.pop();
			ans[cur] = c;
			c++;
		}
	} else {
		printf("NO\n");
		return 0;
	}

	for (int i = 0; i < n; i++)
		if (ans[i] == -1 || !(1 <= ans[i] && ans[i] <= k)) {
			printf("NO\n");
			return 0;
		}
	printf("YES\n");
	for (int i = 0; i < n; i++)
		printf("%d ", ans[i]);

	return 0;
}
