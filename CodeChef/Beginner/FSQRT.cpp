#include <bits/stdc++.h>

using namespace std;

int main()
{
	int ncase;
	scanf("%d", &ncase);

	for(int i = 0; i < ncase; i++) {
		int n;
		scanf("%d", &n);
		
		printf("%d\n", (int)floor(sqrt(n)));

		/*
		int ans = 1;
		while( (ans + 1) * (ans + 1) <= n)
			ans++;
		printf("%d\n", ans);
		*/
	}

	return 0;
}
