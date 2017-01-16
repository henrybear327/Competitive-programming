#include <bits/stdc++.h>

using namespace std;

int main()
{
	int ncase;
	scanf("%d", &ncase);

	while(ncase--) {
		int r, c, x, y;
		scanf("%d %d %d %d", &r, &c, &x, &y);
		
		int val = (x + 1) ^ (r - x) ^ (y + 1) ^ (c - y);
		printf("%s\n", val == 0 ? "Hansel" : "Gretel");
	}

	return 0;
}
