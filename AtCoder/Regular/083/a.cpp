#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ll a, b, c, d, e, f;
    scanf("%lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f);

    set<ll> denominator;
    for(int i = 0; i <= 100; i++)
        for(int j = 0; j <= 100; j++) {
            denominator.insert(100 * a * i + 100 * b * j);
        }
    denominator.erase(0);

    set<ll> numerator;
    for(int i = 0; i <= 1000; i++)
        for(int j = 0; j <= 1000; j++) {
            if(c * i + d * j > 3000)
                break;
            numerator.insert(c * i + d * j);
        }

    ll ansUpper = 0;
    ll ansLower = *(denominator.begin());
    // printf("%d %d\n", numerator.size(), denominator.size());
    for(auto i : numerator)
        for(auto j : denominator) {
            ll upper = i;
            ll lower = j;

            if(upper + lower > f)
                continue;
    
            {
                int newUpper = 100 * upper;
                int newE = e * lower;

                if(newUpper > newE)
                    continue;
            }
            
            // printf("%lld %lld\n", lower, upper);

            {
                ll newAnsUpper = ansUpper * lower;
                ll newUpper = upper * ansLower;

                if(newUpper > newAnsUpper) {
                    ansUpper = upper;
                    ansLower = lower;
                }
            }
            
        }
    
    printf("%lld %lld\n", ansLower + ansUpper, ansUpper);

    return 0;
}
