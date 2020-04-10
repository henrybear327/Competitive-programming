#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while (ncase--) {
        int n;
        scanf("%d", &n);

        int inp[n];
        for (int i = 0; i < n; i++)
            scanf("%d", &inp[i]);

        sort(inp, inp + n);
        reverse(inp, inp + n);

        for (int i = 0; i < n; i++)
            printf("%d%c", inp[i], i == n - 1 ? '\n' : ' ');
    }

    return 0;
}
