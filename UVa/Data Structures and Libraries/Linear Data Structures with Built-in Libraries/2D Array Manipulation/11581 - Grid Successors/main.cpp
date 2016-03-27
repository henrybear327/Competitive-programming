#include <cstdio>

int original[3][3];
int data[3][3];

bool verify(void)
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (data[i][j] != original[i][j])
                return false;

    int zero = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (data[i][j] == 0)
                zero++;
    if (zero != 9)
        return false;
    else
        return true;
}

const int direction[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

int main()
{
    int cases;
    scanf("%d", &cases);
    while (cases--) {
        for (int i = 0; i < 3; i++) {
            int tmp;
            scanf("%d", &tmp);
            for (int j = 2; j >= 0; j--) {
                data[i][j] = tmp % 10;
                tmp /= 10;
            }
        }

        int ans = -1;
        while (!verify()) {
            ans++;
            int tmp[3][3];

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    tmp[i][j] = 0;
                    for (int k = 0; k < 4; k++) {
                        if (i + direction[k][0] >= 0 && i + direction[k][0] < 3 &&
                            j + direction[k][1] >= 0 && j + direction[k][1] < 3)
                            tmp[i][j] += data[i + direction[k][0]][j + direction[k][1]];
                    }

                    if (tmp[i][j] % 2)
                        tmp[i][j] = 1;
                    else
                        tmp[i][j] = 0;
                }
            }

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    data[i][j] = tmp[i][j];
                }
            }

            /*
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    printf("%d ", data[i][j]);
                }
                printf("\n");
            }
            */
        }

        printf("%d\n", ans);
    }

    return 0;
}
