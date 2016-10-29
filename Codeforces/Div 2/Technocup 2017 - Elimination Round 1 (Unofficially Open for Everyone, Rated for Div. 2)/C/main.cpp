#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int main()
{
	int n;
	scanf("%d", &n);
		
	int ans[n + 1];

	printf("? 1 2\n");
	fflush(stdout);
	ll x;
	scanf("%lld", &x);

	printf("? 1 3\n");
	fflush(stdout);
	ll y;
	scanf("%lld", &y);

	printf("? 2 3\n");
	fflush(stdout);
	ll z;
	scanf("%lld", &z);

	ll sum = x + y + z;
	sum /= 2;

	ans[1] = sum - z;
	ans[3] = sum - x;
	ans[2] = sum - ans[1] - ans[3];
	
	for(int i = 4; i <= n; i++) {
		printf("? %d %d\n", i - 1, i);
		fflush(stdout);
		ll tmp;
		scanf("%lld", &tmp);

		ans[i] = tmp - ans[i - 1];
	}

	printf("! ");
	for(int i = 1; i <= n; i++)
		printf("%d ", ans[i]);
	
    return 0;
}
