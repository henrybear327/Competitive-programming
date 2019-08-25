#include <bits/stdc++.h>

using namespace std;

int main()
{
    // 4 , 8, 15, 16, 23, 42
    // strategy is ask (1, 2) (2, 3) (3, 4) (4, 5)
    // we can infer 2, 3, 4 by GCD, and then 1, 5, and the remaining number is for
    // 6

    // we can also get 3 numbers by asking 2 queries
    // ask (1, 2) (2, 3) -> we can get 2 and infer 1, 3

    int inp[4];
    printf("? 1 2\n");
    fflush(stdout);
    scanf("%d", &inp[0]);

    printf("? 2 3\n");
    fflush(stdout);
    scanf("%d", &inp[1]);

    printf("? 3 4\n");
    fflush(stdout);
    scanf("%d", &inp[2]);

    printf("? 4 5\n");
    fflush(stdout);
    scanf("%d", &inp[3]);

    int orig[] = {4, 8, 15, 16, 23, 42};
    do {
        int tmp[4];
        for (int i = 0; i < 4; i++)
            tmp[i] = orig[i] * orig[i + 1];

        bool ok = true;
        for (int i = 0; i < 4; i++)
            if (tmp[i] != inp[i])
                ok = false;

        if (ok == true) {
            printf("! ");
            for (int i = 0; i < 6; i++)
                printf("%d%c", orig[i], i == 5 ? '\n' : ' ');
            return 0;
        }
    } while (next_permutation(orig, orig + 6));

    return 0;
}
