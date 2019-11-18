#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);

    int mx[n - 1];
    for (int i = 0; i < n - 1; i++)
        scanf("%d", &mx[i]);

    int ans = mx[0] + mx[n - 2];
    for (int i = 0; i < n - 2; i++) {
        ans += min(mx[i], mx[i + 1]);
    }

    printf("%d\n", ans);

    return 0;
}
