#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    while (n--) {
        int total, nth;
        scanf("%d %d", &total, &nth);

        int inp[total];
        for (int i = 0; i < total; i++)
            scanf("%d", &inp[i]);
        sort(inp, inp + total);
        printf("%d\n", inp[total - nth]);
    }

    return 0;
}
