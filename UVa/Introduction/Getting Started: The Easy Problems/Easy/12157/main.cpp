#include <cstdio>

int Mile(int x)
{
    return (x / 30 + 1) * 10;
}

int Juice(int x)
{
    return (x / 60 + 1) * 15;
}

int main()
{
    int cases;
    scanf("%d", &cases);
    int index = 1;
    while (cases--) {
        int a = 0, b = 0;

        int t;
        scanf("%d", &t);
        while (t--) {
            int tmp;
            scanf("%d", &tmp);
            a += Mile(tmp);
            b += Juice(tmp);
        }

        if (a < b)
            printf("Case %d: Mile %d\n", index++, a);
        else if (a > b)
            printf("Case %d: Juice %d\n", index++, b);
        else
            printf("Case %d: Mile Juice %d\n", index++, a);
    }

    return 0;
}
