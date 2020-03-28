#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n, k;
    scanf("%d %d", &k, &n);

    int inp[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &inp[i]);

    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        int nxt = (i + 1) % n;

        ans = min(ans, k - (inp[nxt] - inp[i] + k) % k);
    }

    printf("%d\n", ans);

    return 0;
}
