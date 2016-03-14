#include <stdio.h>

int main()
{
    int inp;
    int max_so_far = 0, max = 0;
    while (scanf("%d", &inp) == 1) {
        max_so_far += inp;
        max = max_so_far > max ? max_so_far : max;
        if (max_so_far < 0)
            max_so_far = 0;
    }

    printf("%d\n", max);

    return 0;
}
