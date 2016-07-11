#include <bits/stdc++.h>
//LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

typedef long long int ll;

using namespace std;

ll gcd(ll a, ll b) 
{
    return a == 0 ? b : gcd(b % a, a);
}

int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
	ll a, b;
	scanf("%lld %lld", &a, &b);
	if(gcd(a, b) == 1)
	    printf("Nao\n");
	else
	    printf("Sim\n");
    }

    return 0;
}
