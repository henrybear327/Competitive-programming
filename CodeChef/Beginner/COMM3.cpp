#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

inline int dist(ii a, ii b)
{
	int x1 = a.first;
	int y1 = a.second;
	int x2 = b.first;
	int y2 = b.second;
	
	int dx = x1 - x2;
	int dy = y1 - y2;
	return (dx * dx) + (dy * dy);
}

void solve() {
	int limit;
	scanf("%d", &limit);
	
	ii inp[3];
	for(int i = 0; i < 3; i++)
		scanf("%d %d", &inp[i].first, &inp[i].second);
	
	int cnt = 0;
	for(int i = 0; i < 3; i++)
		for(int j = i + 1; j < 3; j++) {
			if(dist(inp[i], inp[j]) <= limit * limit)
				cnt++;
		}
	
	printf("%s\n", cnt >= 2 ? "yes" : "no");
}

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while (ncase--) {
        solve();
    }

    return 0;
}
