#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

/*
   ll f(ll x)
   {
   if (x <= 0)
   return 0;
// 2^40 > 10^12
ll acc[40] = {0};
for (int i = 0; i < 40; i++) {
ll mod = (1LL << (i + 1));

acc[i] += x / mod * mod / 2;
ll rem = x % mod - (mod / 2 - 1);
if (rem > 0)
acc[i] += rem;
}

ll ans = 0;
for (int i = 0; i < 40; i++)
if (acc[i] % 2 == 1)
ans |= (1LL << i);
return ans;
}

int main()
{
ll a, b;
scanf("%lld %lld", &a, &b);

printf("%lld\n", f(b) ^ f(a - 1));

return 0;
}
 */

int main()
{
    ll a, b;
    scanf("%lld %lld", &a, &b);

    ll ans = 0;
    if (a % 2 == 0 && b % 2 == 0)
        ans = b;
    else if (a % 2 == 1 && b % 2 == 0)
        ans = a ^ b;
    else if (a % 2 == 0 && b % 2 == 1)
        ans = 0;
    else
        ans = a;

    if (a % 2 == 1)
        a++;
    if (b % 2 == 0)
        b--;
    if (a <= b)
        ans ^= ((b - a + 1) / 2 % 2);
    printf("%lld\n", ans);
    return 0;
}
