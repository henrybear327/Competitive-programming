#include <bits/stdc++.h>
//LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

typedef long long int ll;

using namespace std;

map<int, int> im;
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    
    map<int, int> inp;
    for(int i = 0; i < n; i++) {
	int tmp;
	scanf("%d", &tmp);
	inp[tmp] = i;
    }
    
    for(int i = 0; i < m; i++) {
	int a, b;
	scanf("%d %d", &a, &b);

	int ia = inp[a], ib = inp[b];
	if(ia > ib)
	    swap(ia, ib);
	im[ia] = ib;
    }

    ll ans = 0;
    int begin = 0, end = -1;
    for(auto i : im) {
	if(end == -1) {
	    end = i.second;
	    ll diff = end - begin;
	    ans += (1 + diff) * diff / 2;
	    begin = end;
	} else {
	    if(i.first < begin)
		continue;
	    end = i.second;
	    ll diff = end - begin;
	    ans += (1 + diff) * diff / 2;
	    begin = end;
	}
    }
    ll diff = n - begin;
    ans += (1 + diff) * diff / 2;

    printf("%lld\n", ans);

    return 0;
}
