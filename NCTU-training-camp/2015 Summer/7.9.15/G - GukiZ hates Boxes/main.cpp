#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <queue>
#include <vector>

int main()
{
    int piles, students;
    while (scanf("%d %d", &piles, &students) == 2) {
        int box[piles], total_boxes = 0;
        for (int i = 0; i < piles; i++) {
            scanf("%d", &box[i]);
            total_boxes += box[i];
        }

        int max_pos = 0;
        for (int i = 0; i < piles; i++)
            if (box[i] != 0)
                max_pos = i;

        if (total_boxes > students) {
            if (total_boxes % students)
                total_boxes = total_boxes / students + 1;
            else
                total_boxes /= students;
        } else {
            total_boxes = 1;
        }

        printf("%d\n", max_pos + 1 + total_boxes);
    }

    return 0;
}