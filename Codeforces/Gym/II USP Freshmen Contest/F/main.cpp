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
    int n, k, m;
    scanf("%d %d %d", &n, &m, &k);

    int mustAttend = 0.7 * (double) n;
    
    bool error = false;
    if( (double) mustAttend / (double) n < 0.7) {
	if(mustAttend + 1 <= n)
	    mustAttend++;
	else
	    error = true;
    }

    if(mustAttend - k < 0)
	mustAttend = k;
    else if(mustAttend - k > (n - m))
	error = true;

    if(error == true) {
	printf("-1\n");
    } else {
	printf("%d\n", mustAttend - k);
    }

    double tmp = 100 * (double) (k + (n - m)) / (double) n;
    int ans = tmp;

    printf("%d\n", ans);

    return 0;
}
