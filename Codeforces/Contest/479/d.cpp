#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

// observation
// can only *2 or /3
// if a number consists of some 2, the next one that is mul of 2 will only have
// more if a number consists of some 3, the next one that is mul of 3 will only
// have less

ii get(ll a)
{
    int cnt2 = 0, cnt3 = 0;
    while (a > 0) {
        if (a % 2 == 0) {
            cnt2++;
            a /= 2;
        } else if (a % 3 == 0) {
            cnt3++;
            a /= 3;
        } else {
            break;
        }
    }

    return ii(cnt2, cnt3);
}

int main()
{
    int n;
    scanf("%d", &n);

    ll inp[n];
    for (int i = 0; i < n; i++)
        scanf("%lld", &inp[i]);

    sort(inp, inp + n, [](const ll &a, const ll &b) {
        ii ra = get(a);
        ii rb = get(b);

        if (ra.first == rb.first)
            return ra.second > rb.second;
        return ra.first < rb.first;
    });

    for (auto i : inp)
        printf("%lld ", i);

    return 0;
}
