#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while (ncase--) {
        ll n, k;
        scanf("%lld %lld", &n, &k);

        ll orig = k;
        ll inp[n];
        for (int i = 0; i < n; i++)
            scanf("%lld", &inp[i]);

        while (true) {
            ll cnt = 0;
            bool done = true;
            for (int i = 0; i < n; i++) {
                if (inp[i] != 0)
                    done = false;
                cnt += inp[i] % orig;
                inp[i] /= orig;
            }
            if (done == true)
                break;

            if (cnt <= 1) {
                k *= orig;
            } else {
                printf("NO\n");
                goto done;
            }
        }

        printf("YES\n");
done:
        continue;
    }

    return 0;
}
