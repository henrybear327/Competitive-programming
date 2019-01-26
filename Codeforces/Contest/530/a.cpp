#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int w, h;
    scanf("%d %d", &w, &h);

    int u1, d1, u2, d2;
    scanf("%d %d %d %d", &u1, &d1, &u2, &d2);

    int ans = w;
    for (int i = h; i >= 1; i--) {
        ans += i;
        if (i == d1)
            ans -= u1;
        if (i == d2)
            ans -= u2;
        ans = max(0, ans);
    }

    printf("%d\n", ans);

    return 0;
}
