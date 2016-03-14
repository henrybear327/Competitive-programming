#include <cstdio>

int main()
{
    int cases;
    scanf("%d", &cases);
    while (cases--) {
        int a, b;
        scanf("%d %d", &a, &b);

        printf("%d\n", (a / 3) * (b / 3));
    }

    return 0;
}
