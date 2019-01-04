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

    pair<int, int> inp[200100];
    for(int i = 0; i < n; i++) {
	int x, y;
	scanf("%d %d", &x, &y);

	inp[i].first = x;
	inp[i].second = y;
    }

    sort(inp, inp + n);

    map<int, int> xcnt, ycnt;
    for(int i = 0; i < n; i++) {
	xcnt[inp[i].first]++;
	ycnt[inp[i].second]++;
    }

    ll ans = 0;
    // x==x
    for(auto i : xcnt) {
	ll tmp = i.second;
	if(tmp > 1)
	    ans += (tmp * (tmp - 1) / 2);
    }

    // y==y
    for(auto i : ycnt) {
	ll tmp = i.second;
	if(tmp > 1)
	    ans += (tmp * (tmp - 1) / 2);
    }

    // x==x && y==y
    pair<int, int> prev = inp[0];
    int tmp_cnt = 1;
    for(int i = 1; i <= n; i++) {
	if(i != n && inp[i] == prev) {
	    tmp_cnt++;
	} else {
	    if(tmp_cnt > 1)
		// ans -= tmp_cnt * (tmp_cnt - 1) / 2;
        ans -= tmp_cnt * (tmp_cnt - 1LL) / 2LL; // this way can avoid problems when forget to use ll for tmp_cnt

	    tmp_cnt = 1;
	    if(i == n)
		break;
	    prev = inp[i];
	}
    }

    printf("%lld\n", ans);

    return 0;
}
