#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    int inp[n * 2];
    for (int i = 0; i < n; i++) {
        scanf("%d", &inp[i]);
        inp[i + n] = inp[i];
    }

    // 170 30 150 10
    int l = 0;
    int sum = 0;
    int ans = 360;
    for (int r = 0; r < 2 * n; r++) {
        while (l < r && (r - l >= n || sum >= 180)) {
            sum -= inp[l];
            l++;

            ans = min(ans, abs((360 - sum) - sum));
        }

        sum += inp[r];
        ans = min(ans, abs((360 - sum) - sum));
    }
    printf("%d\n", ans);

    return 0;
}
