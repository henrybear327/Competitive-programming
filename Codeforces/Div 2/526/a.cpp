#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
	int n;
	scanf("%d", &n);

	int inp[n];
	int ans = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &inp[i]);

		ans += inp[i] * (2 * (2 * (i + 1) - 2));
	}

	printf("%d\n", ans);

	return 0;
}
