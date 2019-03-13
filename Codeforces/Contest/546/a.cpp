#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);

    ii inp[n];
    for (int i = 0; i < n; i++)
        scanf("%d %d", &inp[i].first, &inp[i].second);

    int idx;
    scanf("%d", &idx);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (idx > inp[i].second)
            ans++;
    }

    printf("%d\n", n - ans);

    return 0;
}
