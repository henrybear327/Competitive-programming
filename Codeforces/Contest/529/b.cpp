#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);

    int inp[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &inp[i]);
    sort(inp, inp + n);

    int mn = INT_MAX;
    mn = min(mn, inp[n - 1] - inp[0]);
    if (n - 2 >= 0)
        mn = min(mn, inp[n - 2] - inp[0]);
    if (1 <= n - 1)
        mn = min(mn, inp[n - 1] - inp[1]);

    printf("%d\n", mn);
    return 0;
}
