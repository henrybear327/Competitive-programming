#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int main()
{
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);

	set<int> holes;
	for(int i = 0; i < m; i++) {
		int pos;
		scanf("%d", &pos);

		holes.insert(pos);
	}

	int ans = 1;
	for(int i = 0; i < k; i++) {
		int u, v;
		scanf("%d %d", &u, &v);

		if(holes.find(ans) != holes.end()) {
			break;
		}

		if(ans == u || ans == v) {
			if(ans == u)
				ans = v;
			else if(ans == v)
				ans = u;
			if(holes.find(ans) != holes.end()) {
				break;
			}
		}
	}

	printf("%d\n", ans);

	return 0;
}
