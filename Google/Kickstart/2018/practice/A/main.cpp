#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    scanf("%d", &n);

    int city[5555] = {0};
    for (int i = 0; i < n; i++) {
        int s, t;
        scanf("%d %d", &s, &t);

        for (int j = s; j <= t; j++)
            city[j]++;
    }

    int m;
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        int who;
        scanf("%d", &who);
        printf("%d%c", city[who], i == m - 1 ? '\n' : ' ');
    }
}

int main()
{
    int ncase;
    scanf("%d", &ncase);
    for (int i = 1; i <= ncase; i++) {
        printf("Case #%d: ", i);
        solve();
    }
}
