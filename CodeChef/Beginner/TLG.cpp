#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int a = 0, b = 0;
int aa = 0, bb = 0;
void solve()
{
	int x, y;
	scanf("%d %d", &x, &y);

	aa += x;
	bb += y;

	if(aa > bb)
		a = max(a, aa - bb);
	else
		b = max(b, bb - aa);
}

int main()
{
	int ncase;
	scanf("%d", &ncase);

	while(ncase--) {
		solve();
	}

	printf("%d %d\n", a > b ? 1 : 2, a > b ? a : b);

	return 0;
}
