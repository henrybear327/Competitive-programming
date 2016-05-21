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
int solve(int s, int t)
{
    int l = -1, cnt = 0;
    ll sum = 0;
    for(int i = s; i <= t; i++) {
	sum += inp[i];
	if(sum != 0 && l == -1) {
	    l = i;
	} else if(sum == 0 && l != -1) {
	    cnt++;
	    l = -1;
	} else if(sum == 0 && l == -1)
	    cnt++;
    }

    return cnt;
}

int main()
{
    scanf("%d", &n);
    
    for(int i = 1; i <= n; i++) {
	scanf("%lld", &inp[i]);
    }
    
    /*
    map<ll, int> c;
    int ans = INT_MAX;
    ll sum = 0;
    for(int i = 1; i <= n; i++) {
	sum += inp[i];
	c[sum]++;
	ans = min(ans, n - c[sum]);
    }
    printf("%d\n", ans);
    */

    inp[n + 1] = inp[1];
    inp[0] = inp[n];
    
    int ans = INT_MAX;
    // l to r
    ans = min(ans, n - solve(1, n));

    // l + 1 to r + 1
    ans = min(ans, n - solve(2, n + 1));

    // r to l
    reverse(inp, inp + n + 2);
    ans = min(ans, n - solve(1, n));

    // r - 1 to l - 1
    ans = min(ans, n - solve(0, n - 1));

    printf("%d\n", ans == INT_MAX ? 0 : ans);

    return 0;
}
