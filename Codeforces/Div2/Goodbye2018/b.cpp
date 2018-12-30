#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int n;
    scanf("%d", &n);

    ll sx = 0, sy = 0;
    for (int i = 0; i < 2 * n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);

        sx += x;
        sy += y;
    }

    sx /= n;
    sy /= n;

    printf("%lld %lld\n", sx, sy);

    return 0;
}
