#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int open[n] = {0}, close[n] = {0};
    for (int i = 0; i < m; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        l--;
        r--;

        open[l]++;
        close[r]++;
    }

    int cnt = 0;
    int acc = 0;
    for (int i = 0; i < n; i++) {
        acc += open[i];
        if (acc == m)
            cnt++;
        acc -= close[i];
    }

    printf("%d\n", cnt);

    return 0;
}
