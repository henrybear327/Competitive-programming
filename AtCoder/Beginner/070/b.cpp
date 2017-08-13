#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);

	int mn = min(b, d);
	int mx = max(a, c);
	printf("%d\n", max(0, mn - mx));

	return 0;
}
