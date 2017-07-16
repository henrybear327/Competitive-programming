// http://codeforces.com/problemset/problem/50/A
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
	int x, y;
	scanf("%d %d", &x, &y);

	int mx = max(x, y);
	int mn = min(x, y);

	int ans = mx * (mn / 2);
	if(mn % 2 == 1)
		ans += mx / 2;
	
	printf("%d\n", ans);
	
	return 0;
}
