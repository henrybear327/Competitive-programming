#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

/*
1/k = 1/x +1/y
1/k = (x + y) / (xy)

We know x = y case will be x = y = 2k
So we let y decrease from 2k till y - k == 1 (y - k <= 0 is meaningless), and we calculate x by using x = yk / (y - k)
*/

int main()
{
	int k;
	while(scanf("%d", &k) == 1) {
		int y = 2 * k;
		vector<ii> ans;
		for(; y > k; y--) {
			if( (y * k) % (y - k) != 0)
				continue;
			int x = (y * k) / (y - k);
			ans.push_back(ii(x, y));
		}
		
		sort(ans.begin(), ans.end());
		reverse(ans.begin(), ans.end());
		
		printf("%d\n", (int)ans.size());
		for(auto i : ans)
			printf("1/%d = 1/%d + 1/%d\n", k, i.first, i.second);
	}

	return 0;
}
