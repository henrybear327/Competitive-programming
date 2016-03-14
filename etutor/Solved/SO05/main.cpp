#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while (ncase--) {
        int n;
        scanf("%d", &n);
        int inp[2 * n];
        n *= 2;
        for (int i = 0; i < n; i++)
            scanf("%d", &inp[i]);
        sort(inp, inp + n);

        if (n % 2 == 0)
            printf("%d\n", inp[n / 2 - 1]);
        else
            printf("%d\n", inp[n / 2]);
    }

    return 0;
}
