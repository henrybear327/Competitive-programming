#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <queue>
#include <vector>

int main()
{
    int numbers;
    while (scanf("%d", &numbers) == 1) {
        int data[numbers + 1];
        int *first_occur = (int *)calloc(1000001, sizeof(int));
        int *last_occur = (int *)calloc(1000001, sizeof(int));
        int *count = (int *)calloc(1000001, sizeof(int));
        int max = 0;
        for (int i = 1; i <= numbers; i++) {
            scanf("%d", &data[i]);
            count[data[i]]++;

            if (first_occur[data[i]] == 0) {
                first_occur[data[i]] = i;
                // printf("%d %d\n", i, data[i]);
            }
            last_occur[data[i]] = i;

            if (max < count[data[i]]) {
                max = count[data[i]];
            }
        }
        // printf("%d\n", max);
        // printf("%d\n", count[6]);
        int min_dist = 10000000, min_num = 0;
        for (int i = 1; i <= 1000000; i++) {
            if (count[i] == max) {
                // printf("%d %d %d\n", i, last_occur[i], first_occur[i]);
                if (min_dist > (last_occur[i] - first_occur[i])) {
                    min_dist = (last_occur[i] - first_occur[i] + 1);
                    min_num = i;
                }

                // printf("%d\n", last_occur[i] - first_occur[i] + 1);
            }
        }
        // printf("%d\n", min_num);

        printf("%d %d\n", first_occur[min_num], last_occur[min_num]);
    }

    return 0;
}
//4 
//4 6 6 4