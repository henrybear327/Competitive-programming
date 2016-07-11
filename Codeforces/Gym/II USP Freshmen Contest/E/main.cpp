#include <bits/stdc++.h>
//LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

typedef long long int ll;

using namespace std;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    
    ll inp[n + 1];
    for(int i = 1; i <= n; i++)
	scanf("%lld", &inp[i]);

    ll dp[n + 1];
    dp[0] = 0;
    for(int i = 1; i <= n; i++)
	dp[i] = inp[i] + dp[i - 1];

    for(int i = 0; i < m; i++) {
	int l, r;
	scanf("%d %d", &l, &r);

	ll s = dp[r] - dp[l - 1];
	if(s % 2 == 0)
	    printf("Sim\n");
	else
	    printf("Nao\n");
    }

    return 0;
}
