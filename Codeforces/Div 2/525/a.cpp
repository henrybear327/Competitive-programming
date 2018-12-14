#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
	int x;
	scanf("%d", &x);

	for (int i = 1; i <= x; i++)
		for (int j = 1; j <= x; j++) {
			if (i % j == 0 && i * j > x && i / j < x) {
				printf("%d %d\n", i, j);
				return 0;
			}
		}

	printf("-1\n");

	return 0;
}
