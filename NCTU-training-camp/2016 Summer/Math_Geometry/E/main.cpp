#include <bits/stdc++.h>


using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
int main()
{
    int n;
    scanf("%d", &n);

    ll x1, x2;
    scanf("%lld %lld", &x1, &x2);
    
    ii res[n];
    for(int i = 0; i < n; i++) {
	ll k, b;
	scanf("%lld %lld", &k, &b);

	ll yy1 = k * x1 + b;
	ll yy2 = k * x2 + b;
	
	res[i] = ii(yy1, yy2);
    }

    sort(res, res + n);
    bool error = false;
    for(int i = 1; i < n; i++) {
	if(res[i].second < res[i - 1].second) // crucial observation
	    error = true;
    }

    printf("%s\n", error ? "YES" : "NO");

    return 0;
}
