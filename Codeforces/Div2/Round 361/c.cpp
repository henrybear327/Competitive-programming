#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

#define N 1000001
ll dp[N];
ll cal(ll mid)
{
    ll cnt = 0;
    for(int i = 2; i < N && dp[i] <= mid; i++) {
	//printf("dp %lld %lld\n", i, dp[i]);
	cnt += (mid / dp[i]);
    }

    return cnt;
}

int main()
{
    for(ll i = 1; i < N; i++) {
	dp[i] = i * i * i;
    }
    
    ll n;
    scanf("%lld", &n);

    ll l = 7, r = LLONG_MAX;
    while(r - l > 1) {
	ll mid = l + (r - l) / 2;
	//printf("mid %lld\n", mid);

	if(cal(mid) <= n - 1)
	    l = mid;
	else
	    r = mid;
    }
    
    if(cal(r) != n)
	printf("-1\n");
    else {
	printf("%lld\n", r);
    }

    return 0;
}
