#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define M 1000000007

ll fast_pow(ll base, ll exp)
{
    ll res = 1;

    while(exp) {
	if(exp & 1) {
	    res *= base;
	    res %= M;
	}

	base *= base;
	base %= M;
	exp >>= 1;
    }

    return res;
}

int main()
{
    int n;
    scanf("%d", &n);

    map<ll, ll> m;

    for(int i = 0; i < n; i++) {
	int num;
	scanf("%d", &num);

	m[num]++;
    }	

    ll res = 1;
    ll comb = 1;
    for(auto i : m) {
	ll cur;
	cur = fast_pow(i.first, (1 + i.second) * i.second / 2);

	res = fast_pow(res, i.second + 1) * fast_pow(cur, comb) % M;

	comb *= i.second + 1;
	comb %= (M - 1);
    }

    printf("%lld\n", res);

    return 0;
}
