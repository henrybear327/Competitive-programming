#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while (ncase--) {
        int tmp;
        int cnt = 0;
        int array[1000] = {0};
        while (scanf("%d", &tmp) == 1 && tmp != -1) {
            array[cnt++] = tmp;
        }

        int divisor;
        scanf("%d", &divisor);

        sort(array, array + cnt);
        /*
        next_permutation will generate the "next" dictionary order
        */

        int ans = 0;
        do {
            /*
            for (int i = 0; i < cnt; i++)
                printf("%d ", array[i]);
            printf("\n");
            */

            int test = 0;
            for (int i = cnt - 1; i >= 0; i--) {
                test *= 10;
                test += array[i];
            }
            // printf("%d\n", test);

            if (test % divisor == 0)
                ans++;

        } while (next_permutation(array, array + cnt));

        printf("%d\n", ans);
    }

    return 0;
}
