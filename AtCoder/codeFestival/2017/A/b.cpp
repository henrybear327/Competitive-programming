#include <bits/stdc++.h>

using namespace std;

int n, m, k;
int cal(int x, int y)
{
    if (n - x < 0)
        return 0;
    int res = m * x + y * (n - x) - y * x;

    return res < 0 ? 0 : res;
}

int main()
{
    scanf("%d %d %d", &n, &m, &k);

    bool ok = false;
    for (int x = 0; x <= n; x++)
        for (int y = 0; y <= m; y++) {
            if (cal(x, y) == k)
                ok = true;
        }

    printf("%s\n", ok ? "Yes" : "No");

    return 0;
}
