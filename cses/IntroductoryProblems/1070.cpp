#include <bits/stdc++.h>

using namespace std;

int main()
{
    /*
    2 4 1 3 6 8 5 7

    1 6 2 7 3 8 4 9 5 10
    1 2 3 4 5 ... interleave with 6 7 8 9 10 ...

    odds then evens
    */

    int n;
    scanf("%d", &n);

    if (n == 3 || n == 2) {
        printf("NO SOLUTION\n");
    } else if (n == 4) {
        printf("2 4 1 3\n");
    } else {
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                printf("%d ", i / 2 + 1);
            } else {
                printf("%d ", (n + 1) / 2 + (i / 2 + 1));
            }
        }
    }

    return 0;
}
