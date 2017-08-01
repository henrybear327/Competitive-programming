#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

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

        ll sum = 0, cnt = 1;
        for (int i = 0; i < n - 1; i++) {
            if (sum + inp[i] < inp[i + 1]) {
                cnt++;
                sum += inp[i];
            }
        }

        printf("%d\n", cnt);
    }

    return 0;
}