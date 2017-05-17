#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
int main()
{
    int n, w;
    scanf("%d %d", &n, &w);

    ii cup[n];
    for (int i = 0; i < n; i++) {
        int tmp;
        scanf("%d", &tmp);

        cup[i] = ii(tmp, i);
    }

    sort(cup, cup + n);

    int fill[n];
    for (int i = 0; i < n; i++) {
        fill[cup[i].second] = (cup[i].first + 1) / 2;
        w -= fill[cup[i].second];
    }

    if (w < 0) {
        printf("-1\n");
        return 0;
    } else if (w > 0) {
        for (int i = n - 1; i >= 0; i--) {
            int remain = cup[i].first - fill[cup[i].second];

            if (w >= remain) {
                w -= remain;
                fill[cup[i].second] = cup[i].first;
            } else {
                fill[cup[i].second] += w;
                w = 0;
            }
        }

        if (w > 0) {
            printf("-1\n");
            return 0;
        }
    }

    for (int i = 0; i < n; i++)
        printf("%d%c", fill[i], i == n - 1 ? '\n' : ' ');

    return 0;
}
