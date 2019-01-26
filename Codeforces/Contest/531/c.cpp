#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n, x, y;
    scanf("%d %d %d", &n, &x, &y);

    int inp[n];
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &inp[i]);
        if (inp[i] <= x)
            cnt++;
    }

    sort(inp, inp + n);

    if (x > y)
        printf("%d\n", n);
    else
        printf("%d\n", (cnt + 1) / 2);

    return 0;
}
