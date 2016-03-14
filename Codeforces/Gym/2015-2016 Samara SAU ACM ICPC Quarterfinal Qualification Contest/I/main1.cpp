#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

#ifdef WIN_32
#define lld "I64d"
#else
#define lld "lld"
#endif

const ll INF = 0x3FFFFFFFFFFFFFFFLL;

int main()
{
    ll n, d, c;
    scanf("%lld%lld%lld", &n, &d, &c);
    vector<ll> t(n + 1);

    for (int i = 1; i <= n; i++) {
        scanf("%lld", &t[i]);
        t[i] += t[i - 1];
    }

    vector<ll> a(n + 1, INF);
    a[0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            ll cost = ((i - j) * (t[i] - t[i - 1]) - (t[i] - t[j])) * c;
            printf("%d %d %lld\n", i, j, cost);
            a[i] = min(a[i], a[j] + d + cost);
        }
    }

    printf("%lld\n", a[n]);
}
