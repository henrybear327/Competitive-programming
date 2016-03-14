#include <cstdio>
#include <cstdlib>

int main()
{
    int cases;
    scanf("%d", &cases);
    while (cases--) {
        int tmp;
        scanf("%d", &tmp);
        printf("%d\n", abs(((tmp * 567 / 9 + 7492) * 235 / 47 - 498) / 10 % 10));
    }

    return 0;
}
