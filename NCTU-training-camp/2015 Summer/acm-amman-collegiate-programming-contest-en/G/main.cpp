#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <queue>
#include <vector>
#include <climits> //LLONG_MIN LLONG_MAX INT_MIN INT_MAX
#include <cmath>

using namespace std;

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int max_level, target, ans_target, ans_more_than_target;
int coin[10];
int permutation_status[10];
void permutation(int curr_level)
{
    // printf("curr_level %d, max1 %d, max2 %d\n", curr_level, ans_target,
    // ans_more_than_target);
    /*
    for (int i = 0; i < curr_level; i++)
    printf("%d ", permutation_status[i]);
    printf("\n");
    */

    if (curr_level == max_level) {
        int total = 0, count = 0, last_i = 0;
        for (int i = 0; i < curr_level; i++) {
            if (permutation_status[i] == 1) {
                count++;
                total += coin[i];
                last_i = i;
            }
        }
        // printf("%d\n", total);
        if (total == target) {
            ans_target = ans_target > count ? ans_target : count;
        } else if (total > target) {
            if (total - coin[last_i] < target) {
                ans_more_than_target =
                    ans_more_than_target > count ? ans_more_than_target : count;

                for (int i = 0; i < curr_level; i++)
                    printf("%d ", permutation_status[i]);
                printf("\n");
            }
        }

        return;
    }

    for (int i = 0; i <= 1; i++) {
        permutation_status[curr_level] = i;
        permutation(curr_level + 1);
        permutation_status[curr_level] = 0;
    }
}

int main()
{
    int cases;
    scanf("%d", &cases);
    while (cases--) {
        scanf("%d %d", &max_level, &target);
        for (int i = 0; i < max_level; i++)
            scanf("%d", &coin[i]);
        qsort(coin, max_level, sizeof(int), cmp);

        ans_target = 0;
        ans_more_than_target = 0;
        memset(permutation_status, 0, sizeof(permutation_status));
        permutation(0);

        printf("ans %d %d \n", ans_target, ans_more_than_target);
    }

    return 0;
}
