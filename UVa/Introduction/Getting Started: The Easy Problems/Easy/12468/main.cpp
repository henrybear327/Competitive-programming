#include <cstdio>
#include <cstdlib>

int main()
{
    int a, b;
    while (scanf("%d %d", &a, &b) == 2 && (a != -1 && b != -1)) {
        int ans = abs(a - b);
        printf("%d\n", ans == 99 ? 1 : ((ans < 50) ? ans : 100 - ans));
    }

    return 0;
}
