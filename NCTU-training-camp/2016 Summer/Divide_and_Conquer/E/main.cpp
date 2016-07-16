#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
bool check(int inp[], ll mid)
{
    ll cnt = 0;
    for(int i = 0; i < n; i++) {
	if(mid >= inp[i]) {
	    cnt += mid - inp[i];
	    if(cnt >= mid)
		return true;
	}
    }
    return cnt >= mid;
}

int main()
{
    scanf("%d", &n);
    
    int inp[n];
    for(int i = 0; i < n; i++) {
	scanf("%d", &inp[i]);
    }
    sort(inp, inp + n);

    ll l = inp[n - 1] - 1, r = LLONG_MAX; // [l, r)
    while(r - l > 1) {
	ll mid = l + (r - l) / 2;
    
	if(check(inp, mid) == true) {
	    r = mid;
	} else {
	    l = mid;
	}
    }

    printf("%lld\n", r);

    return 0;
}
