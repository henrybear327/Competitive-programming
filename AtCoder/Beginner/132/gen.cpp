#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m;
	printf("%d %d\n", 50001, 49999 * 2);

	for(int i = 1; i <= 49999; i++) {
		printf("%d %d\n", 50000, i);
		printf("%d %d\n", i, 50000);
	}

	printf("%d %d\n", 50000, 50001);

	return 0;
}
