#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <queue>
#include <vector>

int main()
{
    int size;
    while (scanf("%d", &size) == 1) {
        int matrix[size][size];
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                scanf("%d", &matrix[i][j]);

        int DP[size][size];
        memset(DP, 0, sizeof(DP));
        for (int column = 0; column < size; column++) {
            for (int row = 0; row < size; row++) {
                if (row == 0)
                    DP[row][column] = matrix[row][column];
                else
                    DP[row][column] = DP[row - 1][column] + matrix[row][column];
            }
        }

        int max = 0;
        for (int row = 0; row < size; row++) {
            for (int x = row; x < size; x++) {
                int total = 0;
                for (int y = 0; y < size; y++) {
                    int sum = DP[x][y];
                    if (x != row)
                        sum = DP[x][y] - DP[row][y];

                    total += sum;
                    if (total < 0)
                        total = 0;
                    if (total > max)
                        max = total;
                }
            }
        }

        printf("%d\n", max);
    }

    return 0;
}