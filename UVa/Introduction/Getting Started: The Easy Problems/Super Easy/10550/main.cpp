#include <cstdio>

int degree(int a, int b, int is_not_clockwise)
{
    int degree = 0;

    if (is_not_clockwise) {
        if (b < a)
            degree += (b + 40 - a);
        else
            degree += (b - a);
    } else {
        if (b < a)
            degree += (a - b);
        else
            degree += (40 - b + a);
    }

    return degree;
}

int main()
{
    int array[4];

    while (1) {
        int flag = 0;
        for (int i = 0; i < 4; i++) {
            scanf("%d", &array[i]);
            if (array[i] == 0) {
                array[i] = 40;
                flag++;
            }
        }

        if (flag == 4)
            break;

        int ans = 120;

        for (int i = 0; i < 3; i++)
            ans += degree(array[i], array[i + 1], i % 2);

        printf("%d\n", ans * 360 / 40);
    }
    return 0;
}
