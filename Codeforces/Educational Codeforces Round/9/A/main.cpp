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
    ll n, p;
    scanf("%lld %lld", &n, &p);

    int type[40] = {0};
    for(int i = n - 1; i >= 0; i--) {
	char tmp[20];
	scanf("%s", tmp);

	if(strlen(tmp) == 8)
	    type[i] = 1;
    }		    
    
    ll cnt = 0, plus = 0;
    for(int i = 0; i < n; i++) {
	cnt *= 2;
	if(type[i] == 1) {
	    cnt++;
	    plus++;
	}
    }

    ll ans = p * cnt - p / 2 * plus;
    printf("%lld\n", ans);

    return 0;
}
