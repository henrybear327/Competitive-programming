#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);

    int inp[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &inp[i]);

    for (int i = 0; i < (1 << n); i++) {
        int tot = 0;
        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1) {
                tot += inp[j];
            } else {
                tot -= inp[j];
            }
        }

        if (tot % 360 == 0) {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");

    return 0;
}
