#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ll n, k;
    scanf("%lld %lld", &n, &k);

    ll orig = n;

    int two = 0, five = 0;
    while(n % 2 == 0) {
        two++;
        n /= 2;
    }

    while(n % 5 == 0) {
        five++;
        n /= 5;
    }

    int zero = min(two, five);
    two -= zero;
    five -= zero;

    if(zero >= k) {
        printf("%lld\n", orig); 
    } else {
        while(five > 0 && zero < k) {
            zero++;
            orig *= 2;
            five--;
        }

        while(two > 0 && zero < k) {
            zero++;
            orig *= 5;
            two--;
        }

        while(zero < k) {
            zero++;
            orig *= 10;
        }

        printf("%lld\n", orig);
    }

    return 0;
}
