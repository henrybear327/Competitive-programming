#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

void solve()
{
    int n;
    scanf("%d", &n);

    char inp[n + 3];
    scanf("%s", inp);

    char sorted[n + 3];
    strncpy(sorted, inp, n + 3);
    sort(sorted, sorted + n);

    int ans = 0;
    for (int i = 0; i < n; i++)
        if (sorted[i] != inp[i])
            ans++;
    printf("%d\n", ans);
}

int main()
{
    int ncase;
    scanf("%d", &ncase);
    while (ncase--)
        solve();

    return 0;
}
