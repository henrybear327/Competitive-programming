#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);

    char one[n + 3], two[n + 3];
    scanf("%s", one);
    scanf("%s", two);

    int cnt[4] = {0};
    for (int i = 0; i < n; i++) {
        if (one[i] == '0' && two[i] == '0')
            cnt[0]++;
        else if (one[i] == '0' && two[i] == '1')
            cnt[1]++;
        else if (one[i] == '1' && two[i] == '0')
            cnt[2]++;
        else
            cnt[3]++;
    }

    int ans[4];
    memset(ans, -1, sizeof(ans));
    for (int i = 0; i <= cnt[0]; i++)
        for (int j = 0; j <= cnt[3]; j++) {
            int left = i - j;
            int right = n / 2 - cnt[1] - cnt[3];

            if (left == right) {
                for (int p = 0; p <= cnt[1]; p++)
                    for (int q = 0; q <= cnt[2]; q++) {
                        int left1 = p + q;
                        int right1 = cnt[1] + cnt[3] - 2 * j;

                        if (left1 == right1) {
                            ans[1] = p;
                            ans[2] = q;
                            ans[0] = i;
                            ans[3] = j;
                            goto done;
                        }
                    }
            }
        }

done:
    // printf("%d %d %d %d\n", ans[0], ans[1], ans[2], ans[3]);

    for (int i = 0; i < 4; i++)
        if (ans[i] == -1) {
            printf("-1\n");
            return 0;
        }

    for (int i = 0; i < n; i++) {
        if (one[i] == '0' && two[i] == '0') {
            if (ans[0] > 0)
                printf("%d ", i + 1), ans[0]--;
        } else if (one[i] == '0' && two[i] == '1') {
            if (ans[1] > 0)
                printf("%d ", i + 1), ans[1]--;
        } else if (one[i] == '1' && two[i] == '0') {
            if (ans[2] > 0)
                printf("%d ", i + 1), ans[2]--;
        } else {
            if (ans[3] > 0)
                printf("%d ", i + 1), ans[3]--;
        }
    }

    return 0;
}
