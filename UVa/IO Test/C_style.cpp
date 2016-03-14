#include <cstdio>

int main()
{
    int a, b;
    for (int i = 0; i < 99999999; i++) {
        scanf("%d %d", &a, &b);
        printf("%d\n", a - b);
    }

    return 0;
}
