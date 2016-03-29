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
    int n, m;
    scanf("%d %d", &n, &m);
	
    map<int, int> pos;
    for(int i = 0; i < n; i++) {
	int cur;
	scanf("%d", &cur);

	pos[cur] = i;
    }

    int cnt[n];
    fill(cnt, cnt + n, n - 1);

    for(int i = 0; i < m; i++) {
	int a, b;
	scanf("%d %d", &a, &b);
	int ia = pos[a], ib = pos[b];
	if(ia > ib)
	    swap(ia, ib);
	
	for(int j = ia; j >= 0; j--) {
	    if(cnt[j] > ib - 1) // this terminating condition is crucial!
		cnt[j] = ib - 1;
	    else
		break;
	}
    }
    
    ll ans = 0;
    for(int i = 0; i < n; i++) {
	ll diff = cnt[i] - i + 1;
	ans += diff;
    }
    printf("%lld\n", ans);

    return 0;
}
