#include <bits/stdc++.h>
//LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    long long int ans = 0, cnt = 0, mn = LLONG_MAX;
    for(int i = 0; i < n; i++) {
	long long int tmp;
	scanf("%lld", &tmp);

	if(tmp & 1LL == 1) {
	    cnt++;
	    mn = min(mn, tmp);
	}
	ans += tmp;
    }

    if(cnt & 1LL)
	ans -= mn;

    printf("%lld\n", ans);

    return 0;
}
