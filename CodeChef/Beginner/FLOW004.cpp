#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

void solve()
{
	char inp[11];
	scanf("%s", inp);

	printf("%d\n", (inp[0] - '0') + (inp[strlen(inp) - 1] - '0'));
}

int main()
{
	int ncase;
	scanf("%d", &ncase);

	while(ncase--) {
		solve();
	}

	return 0;
}
