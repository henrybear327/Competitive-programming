#include <bits/stdc++.h>

using namespace std;

int cal(int idx, int pos)
{
    int base = 4;
    for (int i = 0; i < pos; i++) {
        base *= 2;
    }

    idx %= base;
    if (idx < base / 2) {
        if (idx < base / 4) {
            return 0;
        } else {
            return 1;
        }
    } else {
        idx -= base / 2;
        if (idx < base / 4) {
            return 1;
        } else {
            return 0;
        }
    }
}

/*
000
001
011
010
110
111
101
100

Each column has it's cycles, which doubles from the column on its right
*/
int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < (1 << n); i++) {
        for (int j = n - 1; j >= 0; j--) {
            printf("%d", cal(i, j));
        }
        printf("\n");
    }

    return 0;
}
