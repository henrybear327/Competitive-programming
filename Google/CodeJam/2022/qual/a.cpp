#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int r, c;
    scanf("%d %d", &r, &c);

    for (int i = 0; i < r; i++) {
        if (i == 0) {
            printf("\n");

            // print top
            for (int j = 0; j < 2 * c + 1; j++) {
                if (j <= 1) {
                    printf(".");
                } else {
                    printf("%c", "+-"[j % 2]);
                }
            }
            printf("\n");
        }
        // print middle
        for (int j = 0; j < 2 * c + 1; j++) {
            if (i == 0 && j == 0) {
                printf(".");
            } else {
                printf("%c", "|."[j % 2]);
            }
        }
        printf("\n");

        // print bottom
        for (int j = 0; j < 2 * c + 1; j++) {
            printf("%c", "+-"[j % 2]);
        }
        printf("\n");
    }
}

int main()
{
    int ncase;
    scanf("%d", &ncase);

    for (int i = 1; i <= ncase; i++) {
        printf("Case #%d: ", i);
        solve();
    }

    return 0;
}
