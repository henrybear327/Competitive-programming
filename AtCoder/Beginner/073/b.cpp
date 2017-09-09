#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int l, r;
        scanf("%d %d", &l, &r);

        ans += r - l + 1;
    }

    printf("%d\n", ans);

    return 0;
}
