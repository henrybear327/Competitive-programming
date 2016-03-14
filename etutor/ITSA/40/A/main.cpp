#include <cstdio>

int main()
{
    int cases;
    scanf("%d", &cases);
    getchar();
    while (cases--) {
        char sign;
        int a1, a2, b1, b2;
        scanf("%c %d %d %d %d", &sign, &a1, &a2, &b1, &b2);
        getchar();

        if (sign == '+')
            printf("%d %d\n", a1 + b1, a2 + b2);
        else if (sign == '-')
            printf("%d %d\n", a1 - b1, a2 - b2);
        else if (sign == '*')
            printf("%d %d\n", a1 * b1 - a2 * b2, a2 * b1 + a1 * b2);
    }

    return 0;
}
