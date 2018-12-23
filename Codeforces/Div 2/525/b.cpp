#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    int inp[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &inp[i]);
    sort(inp, inp + n);

    ll acc = 0;
    int idx = 0;
    while (k--) {
        if (idx < n) {
            ll diff = inp[idx] - acc;
            printf("%lld\n", diff);

            int mn = inp[idx];
            while (idx < n && mn == inp[idx])
                idx++;
            acc = mn;
        } else {
            printf("0\n");
        }
    }

    return 0;
}
