#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

// the key insight is...
// you simply set the people going through per second to the bottleneck value!!!

int main()
{
    ll n;
    scanf("%lld", &n);
    ll mn = LLONG_MAX;
    for (int i = 0; i < 5; i++) {
        ll num;
        scanf("%lld", &num);

        mn = min(mn, num);
    }

    ll group = (n + mn - 1) / mn;
    printf("%lld\n", 5 + group - 1);

    return 0;
}
