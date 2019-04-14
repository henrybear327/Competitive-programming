#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
	int n, t;
	scanf("%d %d", &n, &t);
	
	int bus = 0, diff = INT_MAX;
	for(int i = 0; i < n; i++) {
		int s, d;
		scanf("%d %d", &s, &d);

		for(int j = s; j < 3 * 100001; j += d) {
			if(j >= t) {
				if(diff > j - t) {
					diff = j - t;
					bus = i;
					break;
				}
			}
		}
	}

	printf("%d\n", bus + 1);

    return 0;
}
