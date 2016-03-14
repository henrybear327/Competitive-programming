#include <cstdio>

int main()
{
    int cases;
    scanf("%d", &cases);

    int count = 1;

    while (cases--) {
        int walls;
        scanf("%d", &walls);

        int high = 0, low = 0, prev;
        scanf("%d", &prev);

        while (walls-- > 1) {
            int curr;
            scanf("%d", &curr);

            if (curr > prev)
                high++;
            else if (curr < prev)
                low++;
            prev = curr;
        }

        printf("Case %d: %d %d\n", count++, high, low);
    }

    return 0;
}
