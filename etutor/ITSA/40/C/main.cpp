#include <cstdio>
#include <cstring>

int main()
{
    int cases;
    scanf("%d", &cases);
    while (cases--) {
        int N, S;
        scanf("%d %d", &N, &S);

        int ans[N][N];
        memset(ans, 0, sizeof(ans));
        if (S == 1) {
            int x = N - 1;
            for (int i = 0; i < N; i++)
                ans[i][x--] = -1;
        } else if (S == 2) {
            for (int i = 0; i < N; i++)
                ans[i][i] = -1;
        } else if (S == 3) {
            for (int i = 0; i < N; i++)
                ans[i][N - 1] = -1;
        } else if (S == 4) {
            for (int i = 0; i < N; i++)
                ans[i][0] = -1;
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (j == N - 1)
                    printf("%c\n", ans[i][j] == 0 ? 'x' : '*');
                else
                    printf("%c ", ans[i][j] == 0 ? 'x' : '*');
            }
        }
    }
    return 0;
}
