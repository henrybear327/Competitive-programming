#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF) {
        printf("%d %d\n", m, n);
        int idx = 0;
        pair<pair<int, int>, int> data[1010];

        for (int i = 1; i <= n; i++) {
            int tot;
            scanf("%d", &tot);

            for (int j = 0; j < tot; j++) {
                int tmp;
                scanf("%d", &tmp);
                data[idx + j].first.first = tmp;
                data[idx + j].first.second = i;
            }

            for (int j = 0; j < tot; j++) {
                int tmp;
                scanf("%d", &tmp);
                data[idx++].second = tmp;
            }
        }

        sort(data, data + idx);

        /*
        for (int i = 0; i < idx; i++)
            printf("%d %d %d\n", data[i].first.first, data[i].first.second,
                   data[i].second);
        */
        int cnt_row[1010] = {0};
        for (int i = 0; i < idx; i++) {
            cnt_row[data[i].first.first]++;
        }

        int curr = 0;
        for (int i = 1; i <= m; i++) {
            int total = cnt_row[i];
            printf("%d%s", total, total == 0 ? "\n\n" : " ");
            for (int j = 0; j < total; j++) {
                printf("%d%c", data[curr + j].first.second,
                       j == total - 1 ? '\n' : ' ');
            }
            for (int j = 0; j < total; j++) {
                printf("%d%c", data[curr++].second, j == total - 1 ? '\n' : ' ');
            }
        }
    }
    return 0;
}
