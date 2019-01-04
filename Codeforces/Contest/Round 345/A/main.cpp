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
    int a, b;
    scanf("%d %d", &a, &b);
    
    int ans = 0;
    while(a > 2 || b > 2) {
	if(a < b) {
	    int cnt = b / 2;
	    if(b % 2 == 0)
		cnt--;
	    ans += cnt;

	    b -= cnt * 2;
	    a += cnt;
	} else {
	    int cnt = a / 2;
	    if(a % 2 == 0)
		cnt--;
	    ans += cnt;
	    a -= cnt * 2;
	    b += cnt;
	}

	// printf("%d %d\n", a, b);
    }

    if(a <= 1 && b <= 1)
	ans += 0;
    else
	ans += 1;

    printf("%d\n", ans);

    return 0;
}
