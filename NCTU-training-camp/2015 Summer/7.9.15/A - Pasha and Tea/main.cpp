#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MIN(x, y) ((x) < (y) ? (x) : (y))

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

/*
List all inequalities and then just solve for solution!
*/

int main()
{
    int friend_boy, capacity;
    while (scanf("%d %d", &friend_boy, &capacity) == 2) {
        int cup[friend_boy * 2];
        int friend_tot = friend_boy * 2;
        for (int i = 0; i < friend_tot; i++)
            scanf("%d", &cup[i]);
        qsort(cup, friend_tot, sizeof(int), cmp);

        double min_cup_g = cup[0];
        double min_cup_b = cup[friend_tot / 2];

        double X1 = (double)capacity / 3 / friend_boy;
        double X2 = MIN(min_cup_g, (double)min_cup_b / 2);

        printf("%.15f\n", MIN(X1, X2) * 3 * friend_boy);
    }

    return 0;
}