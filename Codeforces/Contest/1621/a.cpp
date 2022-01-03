#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

void solve()
{
    int n, k;
    scanf("%d %d", &n, &k);

    if ((n + 1) / 2 < k) {
        printf("-1\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j && i % 2 == 0 && i / 2 + 1 <= k) {
                printf("R");
            } else {
                printf(".");
            }
            if (j == n - 1)
                printf("\n");
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    while (n--) {
        solve();
    }

    return 0;
}
