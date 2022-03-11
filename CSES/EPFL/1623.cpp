#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    int inp[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &inp[i]);

    long long int diff = LLONG_MAX;
    for (int i = 0; i < (1 << n); i++) {
        long long int a = 0, b = 0;
        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1) {
                a += inp[j];
            } else {
                b += inp[j];
            }
        }

        diff = min(diff, abs(a - b));
    }

    printf("%lld\n", diff);

    return 0;
}
