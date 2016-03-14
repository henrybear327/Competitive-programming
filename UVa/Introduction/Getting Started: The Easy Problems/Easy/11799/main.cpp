#include <cstdio>

int main()
{
    int cases;
    scanf("%d", &cases);

    int index = 1;
    while (cases--) {
        int total;
        scanf("%d", &total);

        int max = -1;
        while (total--) {
            int tmp;
            scanf("%d", &tmp);
            if (tmp > max)
                max = tmp;
        }

        printf("Case %d: %d\n", index++, max);
    }

    return 0;
}
