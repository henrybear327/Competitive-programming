#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while (ncase--) {
        ll n, Q;
        scanf("%lld %lld", &n, &Q);

        ll product = 1;
        int ok = -1;
        ll inp[n];
        for (int i = 0; i < n; i++)
            scanf("%lld", &inp[i]);
        for (int i = 0; i < n; i++) {
            product = ((product % Q) * (inp[i] % Q)) % Q;
            if (product == 1) {
                ok = i + 1;
                break;
            }
        }

        printf("%d\n", ok);
    }

    return 0;
}