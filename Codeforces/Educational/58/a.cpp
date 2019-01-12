#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int q;
    scanf("%d", &q);

    while (q--) {
        int l, r, d;
        scanf("%d %d %d", &l, &r, &d);

        if (l <= d && d <= r) {
            printf("%d\n", (r + d) / d * d);
        } else {
            printf("%d\n", d);
        }
    }

    return 0;
}
