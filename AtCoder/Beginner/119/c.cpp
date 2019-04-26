#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int ans = INT_MAX;

int n, a, b, c;
int inp[10];
int arr[10];
void dfs(int x)
{
    if (x == n) {
        int s[3] = {0};
        int cnt[3] = {0};
        for (int i = 0; i < n; i++)
            if (arr[i] >= 1)
                s[arr[i] - 1] += inp[i], cnt[arr[i] - 1]++;
        for (int i = 0; i < 3; i++)
            if (s[i] == 0)
                return;
        int diff = abs(s[0] - a) + abs(s[1] - b) + abs(s[2] - c);
        for (int i = 0; i < 3; i++)
            if (cnt[i] > 1)
                diff += 10 * (cnt[i] - 1);

        if (ans > diff) {
            /*
                        printf("diff %d\n", diff);
            for (int i = 0; i < n; i++)
                printf("%d ", arr[i]);
            printf("\n");
            for (int i = 0; i < 3; i++)
                printf("%d %d %d\n", i, s[i], cnt[i]);
                        */
        }
        ans = min(ans, diff);

        return;
    }

    for (int i = 0; i < 4; i++) {
        arr[x] = i;
        dfs(x + 1);
    }
}

int main()
{
    /*
    5 100 90 80
    98 80 40 30 21
     */

    scanf("%d %d %d %d", &n, &a, &b, &c);
    for (int i = 0; i < n; i++)
        scanf("%d", &inp[i]);

    dfs(0);

    printf("%d\n", ans);

    return 0;
}
