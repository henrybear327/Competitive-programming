#include <cstdio>
#include <cstdlib>
#include <cstring>

bool used[20];
int ans[20];

int prime[11] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31}; // 15 + 16 = 31!!!

int n;
void dfs(int pos)
{
    if (pos == n) {
        bool ok = false;
        for (int j = 0; j < 11; j++) {
            if (abs(ans[pos - 1] + 1) == prime[j])
                ok = true;
        }
        if (!ok)
            return;

        for (int i = 0; i < n; i++)
            printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');

        return;
    }

    for (int i = 2; i <= n; i++) {
        if (used[i] == false) {
            bool ok = false;
            for (int j = 0; j < 11; j++) {
                if (abs(ans[pos - 1] + i) == prime[j])
                    ok = true;
            }
            if (!ok)
                continue;

            ans[pos] = i;
            used[i] = true;
            dfs(pos + 1);
            ans[pos] = 0;
            used[i] = false;
        }
    }
}

int main()
{
    int cnt = 1;
    while (scanf("%d", &n) == 1) {
        if (cnt != 1)
            printf("\n");

        printf("Case %d:\n", cnt++);
        memset(used, 0, sizeof(used));
        memset(ans, false, sizeof(used));

        ans[0] = ans[n] = 1;
        used[1] = true;

        dfs(1);
    }

    return 0;
}
