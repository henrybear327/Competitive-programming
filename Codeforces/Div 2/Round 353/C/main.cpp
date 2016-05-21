#include <bits/stdc++.h>
//LLONG_MIN LLONG_MAX INT_MIN INT_MAX

// WA
// 7
// 1 3 1 3 1 3 0

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

typedef long long int ll;

using namespace std;

int n;
ll inp[100010];

int main()
{
    scanf("%d", &n);
    
    for(int i = 1; i <= n; i++) 
	scanf("%lld", &inp[i]);
    
    map<ll, int> c;
    int ans = INT_MAX;
    ll sum = 0;
    for(int i = 1; i <= n; i++) {
	sum += inp[i];
	c[sum]++;
	ans = min(ans, n - c[sum]);
    }
    printf("%d\n", ans);

    return 0;
}
