// http://codeforces.com/problemset/problem/318/A
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ll n, k;
    scanf("%lld %lld", &n, &k);
    
    ll odd = (n + 1) / 2;
    ll even = n / 2;
    if(k <= odd) 
        printf("%lld\n", 1 + 2 * (k - 1));
    else
        printf("%lld\n", 2 + 2 * (k - odd - 1));
    
    return 0;
}