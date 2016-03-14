#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    
    int tot[n + 1], cost[n + 1];
    for(int i = 1; i <= n; i++) {
	int a, b;
	scanf("%d %d", &a, &b);

	tot[i] = a;
	cost[i] = b;
    }
    
    int ans = cost[1] * tot[1], prev = 1, mx = cost[1];
    for(int i = 2; i <= n; i++) {
	if(cost[i] > mx)
	    ans += tot[i] * cost[prev];
	else {
	    mx = cost[i];
	    prev = i;
	    ans += tot[i] * cost[i];
	}
    }

    printf("%d\n", ans);

    return 0;
}
