#include <cstdio>
#include <cstdlib>
#include <cmath>

int main()
{
    int cases;
    scanf("%d", &cases);

    while (cases--) {
        int terms;
        scanf("%d", &terms);

        int max = -1, min = 1e9, avg = 0;
        for (int i = 0; i < terms; i++) {
            int tmp;
            scanf("%d", &tmp);
            max = tmp > max ? tmp : max;
            min = tmp < min ? tmp : min;
            avg += tmp;
        }

        avg = (int)round((float)avg / terms);

        printf("%d\n", (max - min) + avg - min + max - avg);
    }

    return 0;
}
