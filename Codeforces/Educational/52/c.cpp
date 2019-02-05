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

    int idx = n;
    int ans = 0;
    ll acc = 0;
    for (int h = inp[n - 1]; h >= inp[0]; h--) {
        // remove all blocks > h
        while (idx > 0 && inp[idx - 1] > h) {
            idx--;
        }
        
        // WTF, can't -= k directly, since we might not be removing <= k blocks...
        if (acc + (n - idx) > k) {
            ans += 1;
            acc = 0;
        }
        acc += n - idx;
    }

    if (acc > 0) {
        ans += 1;
    }

    printf("%d\n", ans);

    return 0;
}
