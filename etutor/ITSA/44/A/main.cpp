#include <cstdio>

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while (ncase--) {
        int a, b;
        scanf("%d %d", &a, &b);

        bool inside = (0 <= a && a <= 100) && (0 <= b && b <= 100);
        printf("%s\n", inside ? "inside" : "outside");
    }

    return 0;
}
