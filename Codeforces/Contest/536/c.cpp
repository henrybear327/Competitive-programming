#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);

    int inp[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &inp[i]);

    sort(inp, inp + n);

    ll ans = 0;
    for(int i = 0; i < n / 2; i++) {
        int tmp = inp[i] + inp[n - 1- i];
        ans += tmp * tmp;
    }

    printf("%lld\n", ans);

    return 0;
}
