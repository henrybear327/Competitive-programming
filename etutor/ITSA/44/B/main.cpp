#include <cstdio>

int m[8][8];

bool ok(int i, int j)
{
    return 0 <= i & i < 8 && 0 <= j && j < 8;
}

bool check()
{
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (m[i][j] == 1) {
                // hor.
                for (int k = 0; k < 8; k++) {
                    if (k != j && m[i][k] == 1)
                        return false;
                }
                // ver.
                for (int k = 0; k < 8; k++) {
                    if (k != i && m[k][j] == 1)
                        return false;
                }
                // diag.
                for (int k = 1; k < 8; k++) {
                    if (ok(i + k, j + k) && m[i + k][j + k])
                        return false;
                    if (ok(i + k, j - k) && m[i + k][j - k])
                        return false;
                    if (ok(i - k, j + k) && m[i - k][j + k])
                        return false;
                    if (ok(i - k, j - k) && m[i - k][j - k])
                        return false;
                }
            }
        }
    }

    return true;
}

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while (ncase--) {
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                scanf("%d", &m[i][j]);

        printf("%c\n", check() ? 'O' : 'X');
    }

    return 0;
}
