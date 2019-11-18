#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);

    int a[n], b[n], c[n - 1];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]), a[i]--;
    for (int i = 0; i < n; i++)
        scanf("%d", &b[i]);
    for (int i = 0; i < n - 1; i++)
        scanf("%d", &c[i]);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += b[a[i]];
        if (i > 0 && a[i - 1] + 1 == a[i])
            ans += c[a[i - 1]];
    }
    printf("%d\n", ans);

    return 0;
}
