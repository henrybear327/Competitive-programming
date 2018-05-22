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
    char inp[300010];
    scanf("%s", inp);

    int n = strlen(inp);
    ll ans = 0;
    for(int i = 0; i < n; i++) {
	if((inp[i] - '0') % 4 == 0)
	    ans++;
	
	if(i - 1 >= 0) {
	    int num = inp[i - 1] - '0';
	    num *= 10;
	    num += inp[i] - '0';
	    if(num % 4 == 0)
		ans += i;
	}
    }

    printf("%lld\n", ans);

    return 0;
}
