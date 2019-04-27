#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);

    int v[n], c[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &c[i]);
    int ans = 0;
    for (int i = 0; i < n; i++)
        if (v[i] > c[i])
            ans += v[i] - c[i];
    printf("%d\n", ans);

    return 0;
}
