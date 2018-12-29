#include <bits/stdc++.h>
//LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

typedef long long int ll;

using namespace std;

const int MOD = (int)1e9 + 7;

int count(char c)
{
    int encode;
    if('0' <= c && c <= '9')
	encode = c - '0';
    else if('a' <= c && c <= 'z')
	encode = c - 'a' + 36;
    else if('A' <= c && c <= 'Z')
	encode = c - 'A' + 10;
    else if(c == '-')
	encode = 62;
    else
	encode = 63;
    
    int res = 0;
    for(int i = 0; i < 6; i++)
	if(((encode >> i) & 1) == 0)
	    res++;
    return res;
}

ll fpow(int k)
{
    if(k == 0)
	return 1LL;
    ll res = 1, base = 3;
    while(k > 0) {
	if(k & 1) {
	    res = ((res % MOD) * (base % MOD)) % MOD;
	}
	k >>= 1;
	base = (base * base) % MOD;
    }
    return res;
}

int main()
{
    char inp[100100];
    scanf("%s", inp);
    
    int len = strlen(inp);
    ll ans = 0;
    for(int i = 0; i <	len; i++) {
	ans += count(inp[i]);
    }

    ans = fpow(ans);

    printf("%lld\n", ans);

    return 0;
}
