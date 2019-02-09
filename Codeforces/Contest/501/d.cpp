#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    ll n, k, s;
    scanf("%lld %lld %lld", &n, &k, &s);

    if (!(k <= s && s <= (n - 1) * k))
        printf("NO\n");
    else {
        printf("YES\n");

        ll pos = 1;
        for (int i = k; i >= 1; i--) {
            ll dist = min(n - 1, s - i + 1);
            s -= dist;

            if ((k - i) % 2 == 0)
                pos += dist;
            else
                pos -= dist;
            printf("%lld ", pos);
        }
    }

    return 0;
}
