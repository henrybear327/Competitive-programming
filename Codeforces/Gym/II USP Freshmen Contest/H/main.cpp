#include <bits/stdc++.h>
//LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

typedef long long int ll;

using namespace std;

#define N 1000010
ll floor1[N], foot[N], chain[N];

int main()
{
    int n;
    scanf("%d", &n);
    
    // floor
    for(int i = 0; i < n; i++)
	scanf("%lld", &floor1[i]);
    
    // foot
    for(int i = 0; i < n; i++)
	scanf("%lld", &foot[i]);

    // chain
    for(int i = 0; i < n; i++)
	scanf("%lld", &chain[i]);

    ll d1 = 0;
    for(int i = 0; i < n; i++) {
	ll tmp = foot[i] - floor1[i];
	d1 += tmp * tmp;
    }

    ll d2 = 0;
    for(int i = 0; i < n; i++) {
	ll tmp = chain[i] - floor1[i];
	d2 += tmp * tmp;
    }

    if(d1 <= d2)
	printf("Yan\n");
    else
	printf("MaratonIME\n");

    return 0;
}
