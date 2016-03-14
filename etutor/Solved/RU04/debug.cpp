/*
clang-format-3.6 -i -style=LLVM debug.cpp && astyle --style=linux debug.cpp &&
clang++-3.6 -Wall -Wextra -o debug.o debug.cpp
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool compute(long long int alligator_legs, long long int bat_eyese,
             long long int cat_skulls, long long int power_A,
             long long int power_B, long long int power_C,
             long long int total)
{
    int i, j, k;

    for (i = 0; i <= alligator_legs; i++) {
        for (j = 0; j <= bat_eyese; j++) {
            for (k = 0; k <= cat_skulls; k++) {
                if (power_A * i + power_B * j + power_C * k == total) {
                    return true;
                }
            }
        }
    }

    return false;
}

int main()
{
    int times;
    long long int alligator_legs, bat_eyes, cat_skulls;
    long long int power_A, power_B, power_C, total;
    int true_or_false;

    scanf("%d", &times);
    getchar();

    while (times--) {
        scanf("%lld%lld%lld%lld%lld%lld%lld", &total, &alligator_legs, &bat_eyes,
              &cat_skulls, &power_A, &power_B, &power_C);
        /*
                printf("total = %d\n", total);
                printf("alligator_legs = %d\n", alligator_legs);
                printf("bat_eyes = %d\n", bat_eyes);
                printf("cat_skulls = %d\n", cat_skulls);
                printf("power_A = %d\n", power_A);
                printf("power_B = %d\n", power_B);
                printf("power_C = %d\n", power_C);
        */
        true_or_false = compute(alligator_legs, bat_eyes, cat_skulls, power_A,
                                power_B, power_C, total);

        if (true_or_false == true) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }

    return 0;
}
