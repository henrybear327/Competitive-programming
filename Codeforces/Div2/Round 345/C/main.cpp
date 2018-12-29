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
    int n;
    scanf("%d", &n);
    
    map<int, ll> X, Y;
    map< pair<int, int>, ll > Z;
    ll ans = 0;
    while(n--) {
	int a, b;
	scanf("%d %d", &a, &b);
	ans += X[a] + Y[b] - Z[make_pair(a, b)];
	X[a]++;
	Y[b]++;
	Z[make_pair(a, b)]++;
    }
    printf("%lld\n", ans);

    return 0;
}
