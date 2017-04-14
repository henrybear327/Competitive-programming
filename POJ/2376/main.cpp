#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> ii;

/*
   1 5
   2 5
   3 6
 */
int main()
{
	int n, t;
	while(scanf("%d %d", &n, &t) == 2) {
		vector<ii> inp;
		for(int i = 0; i < n; i++) {
			int a, b;
			scanf("%d %d", &a, &b);

			inp.push_back(ii(a, b));
		}
		sort(inp.begin(), inp.end());

		int begin = 1, end = 0, ans = 1;
		for(int i = 0; i < n; i++) {
			if(inp[i].first <= begin || inp[i].second <= end) { 
				// the starting point is <= begin or the ending point in less than the current ending point
				if(inp[i].second > end) // extend the end point as far as you can
					end = inp[i].second;
			} else {
				if(inp[i].first - end <= 1) // no gap between extended intervals
					ans++;
				else {
					ans = -1;
					break;
				}
				
				begin = end + 1;
				i--;
			}
		}

		if(end < t) // crucial
			printf("-1\n");
		else
			printf("%d\n", ans);
	}

	return 0;
}
