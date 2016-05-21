#include <bits/stdc++.h>
//LLONG_MIN LLONG_MAX INT_MIN INT_MAX

// WA 0 -1 2 -1

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

typedef long long int ll;

using namespace std;

ll inp[100010];
int n, cnt;
int checkcw(int start)
{
    int step = 0, c = 1;
    ll carry = inp[start];
    for(int i = (start + 1) % n; i != start; i = (i + 1) % n) {
	if(inp[i] >= 0) {
	    carry += inp[i];
	} else {
	    carry -= inp[i];
	    if(carry < 0)
		return INT_MAX;
	}
	step++;

	if(inp[i] != 0)
	    c++;
	if(c == cnt)
	    return step;
    }

    return step;
}

int checkccw(int start)
{
    int step = 0, c = 1;
    ll carry = inp[start];
    for(int i = (start - 1 + n) % n; i != start; i = (i - 1 + n) % n) {
	if(inp[i] >= 0) {
	    carry += inp[i];
	} else {
	    carry -= inp[i];
	    if(carry < 0)
		return INT_MAX;
	}
	step++;

	if(inp[i] != 0)
	    c++;
	if(c == cnt)
	    return step;
    }

    return step;
}

int main()
{
    scanf("%d", &n);
    
    cnt = 0;
    for(int i = 0; i < n; i++) {
	scanf("%lld", &inp[i]);
	if(inp[i] != 0)
	    cnt++;
    }
    
    int ans = INT_MAX;
    for(int i = 0; i < n; i++) {
	if(inp[i] > 0) {
	    ans = min(ans, checkcw(i));
	    ans = min(ans, checkccw(i));
	}
    }

    printf("%d\n", ans == INT_MAX ? 0 : ans);

    return 0;
}
