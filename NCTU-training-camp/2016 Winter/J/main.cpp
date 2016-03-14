#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll fast_pow(ll x, ll n, ll M) {
    /*
    https://henrybear327.gitbooks.io/gitbook_tutorial/content/Algorithm/fast_pow/index.html
    */
    ll result = 1;
    ll base = x;

    while (n != 0) { 
        if (n & 1)
            result = result * base % M;
        base = base * base % M;
        n >>= 1LL; 
    }

    return result;
}

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while(ncase--) {
        int num;
        scanf("%d", &num);
        
        printf("%lld\n", fast_pow(3, num, 100000007) - 1LL);
    }
    return 0;
}