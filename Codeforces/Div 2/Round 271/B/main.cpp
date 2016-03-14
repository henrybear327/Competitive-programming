#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    int inp[n + 1];
    inp[0] = 0;
    for (int i = 1; i <= n; i++) {
        int tmp;
        scanf("%d", &tmp);
        inp[i] = inp[i - 1] + tmp;
    }

    int query;
    scanf("%d", &query);
    for (int i = 0; i < query; i++) {
        int num;
        scanf("%d", &num);

        printf("%d\n", (int)(lower_bound(inp, inp + n, num) - inp));
    }

    return 0;
}
