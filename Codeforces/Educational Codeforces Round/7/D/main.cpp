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

    int ans[2 * n];
    memset(ans, 0, sizeof(ans));

    // odd
    int base = 0;
    for(int i = 1; i < n; i += 2) {
	ans[base] = i;
	ans[base + n - i] = i;
	base++;
    }

    //even
    base = n;
    for(int i = 2; i < n; i += 2) {
	ans[base] = i;
	ans[base + n - i] = i;
	base++;
    }

    // fill the 0 with n
    for(int i = 0; i < 2 * n; i++)
	if(ans[i] == 0)
	    ans[i] = n;
    for(int i = 0; i < 2 * n; i++)
	printf("%d%c", ans[i], i == 2 * n - 1 ? '\n' : ' ');

    return 0;
}
