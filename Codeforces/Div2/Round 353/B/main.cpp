#include <bits/stdc++.h>
//LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

typedef long long int ll;

using namespace std;

int n, a, b, c, d;
bool check(int i, int j)
{
    int sum = i + j + a + b;
    if(!(1 <= sum - a - c - j && sum - a - c - j <= n))
	return false;
    if(!(1 <= sum - b - j - d && sum - b - j - d <= n))
	return false;
    if(!(1 <= sum - j - c - d && sum - j - c - d <= n))
	return false;

    return true;
}

int main()
{
    scanf("%d", &n);
    
    scanf("%d %d %d %d", &a, &b, &c, &d);
    
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
	int l = 0, r = n + 1;
	while(r - l > 1) {
	    int mid = (l + r) / 2;
	    if(check(i, mid)) 
		r = mid;
	    else
		l = mid;
	}
	ans += n - l;
    }

    printf("%lld\n", ans);

    return 0;
}
