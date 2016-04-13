#include <stdio.h>

int main()
{
    int cases;
    scanf("%d", &cases);

    while (cases--) {
        int tot;
        scanf("%d", &tot);

        int leader[10010] = {0};
        for (int i = 2; i <= tot; i++) {
            scanf("%d", &leader[i]);
        }

        int count[10010] = {0};
        for (int i = tot; i >= 1; i--) {
            count[i]++;
            if (i != 1)
                count[leader[i]] += count[i];
        }

        int ans = 0;
        for (int i = 2; i <= tot; i++)
            ans = 2 * count[i] * (tot - count[i]) > ans
                  ? 2 * count[i] * (tot - count[i])
                  : ans;

        printf("%d\n", ans);
    }

    return 0;
}
