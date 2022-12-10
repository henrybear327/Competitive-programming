#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    ll t;
    scanf("%d %lld", &n, &t);

    int inp[n];
    ll tot = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &inp[i]);
        tot += inp[i];
    }

    t %= tot;

    for (int i = 0; i < n; i++) {
        // printf("%d %d %lld\n", i, inp[i], t);
        if (t - inp[i] >= 0) {
            t -= inp[i];
        } else {
            printf("%d %lld\n", i + 1, t);
            break;
        }
    }

    return 0;
}
