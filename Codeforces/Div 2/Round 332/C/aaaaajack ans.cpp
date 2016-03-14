#include <bits/stdc++.h>

#define N 100100

using namespace std;

pair<int, int> orig[N], sorted[N];

/*
10
1 2 2 2 2 2 2 2 2 1
ans:2
*/

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &orig[i].first);
        orig[i].second = i;
        sorted[i] = orig[i];
    }

    sort(sorted, sorted + n);

    int cnt = 0;
    int max_idx = -1;
    for (int i = 0; i < n; i++) {
        // printf("%ld\n", lower_bound(sorted, sorted + n, orig[i]) - sorted);
        max_idx =
            max(max_idx, (int)(lower_bound(sorted, sorted + n, orig[i]) - sorted));
        if (max_idx == i)
            cnt++;
    }

    printf("%d\n", cnt);

    return 0;
}
