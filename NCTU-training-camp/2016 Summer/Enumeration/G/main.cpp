#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int a, b, n;
bool check(int num)
{
    while(num) {
	if(num % 10 == a || num % 10 == b) {
	    num /= 10;
	    continue;
	}
	return false;
    }

    return true;
}   

const int M = (int)1e9 + 7;
const int N = (int)1e6 + 10;
ll dp[N];
void init()
{   
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i < N; i++)
	dp[i] = (dp[i - 1] * i) % M;
}

inline int fac(int x)
{
    return dp[x];
}

int fast_pow(ll base, ll exp, int mod)
{
    ll res = 1;

    while(exp) {
	if(exp & 1) {
	    res = (res * base) % mod;
	}
	base = (base * base) % mod;
	exp >>= 1;
    }

    return (int)res;
}

inline int inv(int num)
{
    return fast_pow(num, M - 2, M);
}

int C(int x)
{
    // n! / (x! * (n - x)!)
    
    return ( ( ( (ll)fac(n) * (ll)inv(fac(x)) ) % M ) * (ll)inv(fac(n - x))) % M;
}

int main()
{
    init();

    scanf("%d %d %d", &a, &b, &n);
    
    int sum;
    ll ans = 0;
    for(int i = 0; i <= n; i++) {
	sum = b * n + (a - b) * i;

	if(check(sum)) {
	    ans = (ans + C(i)) % M;
	}
    }

    printf("%lld\n", ans);

    return 0;
}
