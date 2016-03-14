#include <cstdio>

int main()
{
    int cases;
    while (scanf("%d", &cases) == 1) {
        int k = -1, max_after_k = -1, max_ans = -1;
        scanf("%d %d", &k, &max_ans);
        max_after_k = k;
        cases--;

        while (cases--) {
            int a, b;
            scanf("%d %d", &a, &b);

            if (a > k && a > max_after_k && b > max_ans) {
                k = a;
                max_after_k = a;
                max_ans = b;
            } else if (a > max_after_k) {
                max_after_k = a;
            }
        }

        printf("%d\n", max_ans);
    }

    return 0;
}
