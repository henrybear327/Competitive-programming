#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <queue>
#include <vector>

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    int lantern, length;
    while (scanf("%d %d", &lantern, &length) == 2) {
        int location[lantern];
        for (int i = 0; i < lantern; i++)
            scanf("%d", &location[i]);

        qsort(location, lantern, sizeof(int), cmp);

        double max_diff = 0;
        for (int i = 1; i < lantern; i++) {
            max_diff = max_diff > (location[i] - location[i - 1])
                       ? max_diff
                       : (location[i] - location[i - 1]);
        }
        // printf("%.15f\n", max_diff);

        bool flag = false;
        if (location[0] != 0) {
            if (max_diff / 2 < (location[0] - 0)) {
                max_diff = location[0] - 0;
                flag = true;
            }
        }
        if (location[lantern - 1] != length) {
            if (flag == false) {
                if (max_diff / 2 < (length - location[lantern - 1])) {
                    max_diff = length - location[lantern - 1];
                    flag = true;
                }
            } else {
                if (max_diff < (length - location[lantern - 1])) {
                    max_diff = length - location[lantern - 1];
                }
            }
        }

        if (flag) {
            printf("%.15f\n", (double)max_diff);
        } else
            printf("%.15f\n", (double)max_diff / 2);
    }

    return 0;
}