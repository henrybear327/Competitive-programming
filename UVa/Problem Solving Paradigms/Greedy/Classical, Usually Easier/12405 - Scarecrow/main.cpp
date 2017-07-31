#include <bits/stdc++.h>

using namespace std;

int main()
{
    int ncase;
    scanf("%d", &ncase);

    int cnt = 1;
    while (ncase--) {
        int n;
        scanf("%d", &n);

        char inp[n + 2];
        scanf("%s", inp);

        int res = 0;
        for (int i = 0; i < n; i++)
            if (inp[i] == '.') {
                res++;
                i += 2;
            }

        printf("Case %d: %d\n", cnt++, res);
    }

    return 0;
}