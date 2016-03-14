#include <cstdio>

int main()
{
    int cases;
    while (scanf("%d", &cases) == 1 && cases) {
        int N, M;
        scanf("%d %d", &N, &M);
        while (cases--) {
            int x, y;
            scanf("%d %d", &x, &y);

            if (x == N || M == y)
                printf("divisa\n");
            else if (x < N && M > y)
                printf("SO\n");
            else if (x > N && M > y)
                printf("SE\n");
            else if (x < N && M < y)
                printf("NO\n");
            else
                printf("NE\n");
        }
    }

    return 0;
}
