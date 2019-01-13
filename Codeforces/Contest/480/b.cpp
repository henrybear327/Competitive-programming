#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    char ans[4][n];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < n; j++)
            ans[i][j] = '.';

    bool isOdd = k % 2 == 1;
    if (isOdd)
        k--;

    /*
    .....
    .#.#.
    .....
    .....
    */
    int idx = 1;
    int row = 1;
    while (n != 3 && k > 0) {
        // printf("%d %d\n", row, idx);
        ans[row][idx] = '#';
        k--;

        if (idx < n / 2) {
            idx = (n - 1) - idx;
        } else {
            idx = (n - 1) - idx;
            idx++; // oops
        }

        if (idx == n / 2) { // WOW case 3 2
            row++;
            idx = 1;
        }
        if (row == 3)
            break;
    }

    if (isOdd) {
        ans[1][n / 2] = '#';
    }

    if (k > 0) {
        ans[1][n / 2] = '#';
        ans[2][n / 2] = '#';
    }

    printf("YES\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < n; j++)
            printf("%c", ans[i][j]);
        printf("\n");
    }

    return 0;
}
