#include <cstdio>
#include <cstring>

bool ok[111111];
int used[111111];

int main()
{
    int n, m;
    while (scanf("%d %d", &n, &m) == 2 && (n || m)) {
        int val[n], cnt[n];
        for (int i = 0; i < n; i++)
            scanf("%d", &val[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &cnt[i]);

        memset(ok, 0, sizeof(ok));
        ok[0] = true;
        for (int i = 0; i < n; i++) {
            memset(used, 0, sizeof(used));
            for (int j = 0; j <= m - val[i]; j++) {
                int next = j + val[i];
                if (ok[j] == true && cnt[i] - used[j] > 0 && next <= m &&
                    ok[next] == false) {
                    ok[next] = true;
                    used[next] = used[j] + 1;
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= m; i++) {
            if (ok[i] == true)
                ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
