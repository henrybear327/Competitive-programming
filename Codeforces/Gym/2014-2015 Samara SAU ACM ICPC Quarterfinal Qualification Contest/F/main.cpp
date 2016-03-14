#include <cstdio>

int main()
{
    int a, b, c;
    while (scanf("%d %d %d", &a, &b, &c) == 3) {
        if (a <= c && c <= b)
            printf("Take another envelope\n");
        else
            printf("Stay with this envelope\n");
    }
    return 0;
}
