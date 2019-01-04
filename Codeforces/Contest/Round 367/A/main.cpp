#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int main()
{
	int x, y;
	scanf("%d %d", &x, &y);

	int n;
	scanf("%d", &n);
	
	double ans = INT_MAX;
	for(int i = 0; i < n; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		int dx = a - x, dy = b - y;

		double dist = dx * dx + dy * dy;
		dist = sqrt(dist);

		ans = min(ans, dist / c);
	}

	printf("%.15f\n",ans);

    return 0;
}
