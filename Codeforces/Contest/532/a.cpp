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

    int ans = 0;
    for (int i = 0; i < k; i++) {
        int s = 0, w = 0;
        for (int j = 0; j < n; j++) {
            if (j - i >= 0 && (j - i) % k == 0)
                continue;
            if (inp[j] == 1)
                w++;
            else
                s++;
        }
        ans = max(ans, abs(s - w));
    }

    printf("%d\n", ans);

    return 0;
}
