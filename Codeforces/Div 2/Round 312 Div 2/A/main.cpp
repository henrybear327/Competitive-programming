#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <queue>
#include <vector>

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))

typedef struct tree {
    int position, apple;
} Tree;

int cmp(const void *a, const void *b)
{
    return ((Tree *)a)->position - ((Tree *)b)->position;
}

int main()
{
    int trees;
    while (scanf("%d", &trees) == 1) {
        Tree data[trees];
        int left = -1, right = -1;
        for (int i = 0; i < trees; i++) {
            scanf("%d %d", &data[i].position, &data[i].apple);
            if (data[i].position < 0)
                left++;
            else
                right++;
        }

        qsort(data, trees, sizeof(Tree), cmp);

        int l, r;
        for (int i = 1; i < trees; i++) {
            // printf("%d %d %d\n", data[i].position, data[i].apple, data[i].visited);
            if (data[i].position > 0 && data[i - 1].position < 0) {
                r = i;
                l = i - 1;
            }
        }
        // printf("%d %d\n", l, r);

        if (right == -1)
            l = trees - 1;
        if (left == -1)
            r = 0;
        // printf("%d %d\n", l, r);

        int dir;
        if (left > right)
            dir = -1;
        else
            dir = 1;

        // printf("%d %d\n", left, right);

        int ans = 0;
        while (1) {
            if (dir == 1 && right != -1) {
                if (r >= trees)
                    break;
                ans += data[r].apple;
                r++;
                dir = -1;
            } else if (dir == -1 && left != -1) {
                if (l < 0)
                    break;
                ans += data[l].apple;
                l--;
                dir = 1;
            } else {
                break;
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}
