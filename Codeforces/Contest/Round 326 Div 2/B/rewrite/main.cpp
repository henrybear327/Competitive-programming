#include <bits/stdc++.h>
//LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

typedef long long int ll;

using namespace std;

bool is_prime[1000010];
void gen_table()
{
    is_prime[1] = false;
    for(int i = 2; i < 1000010; i++) {
	if(is_prime[i] == true) {
	    int j = 2;
	    while(i * j < 1000010) {
		is_prime[i * j] = false;
		j++;
	    }
	}
    }
}   

int main()
{
    memset(is_prime, -1, sizeof(is_prime));
    gen_table();

    ll n;
    scanf("%lld", &n);

    map<ll, int> cnt;
    for(ll i = 2; i * i <= n; i++) { // i * i -> long long int!! Stupid mistake!
	if(is_prime[i] == true) {
	    while(n % i == 0) {
		cnt[i]++;
		n /= i;
	    }
	}
    }

    if(n != 1) {
	cnt[n]++;
    }

    ll ans = 1;
    for(auto i : cnt) {
	ans *= i.first;
    }

    printf("%lld\n", ans);

    return 0;
}
