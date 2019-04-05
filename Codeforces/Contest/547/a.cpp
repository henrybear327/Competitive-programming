#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    if (m % n == 0) {
        int k = m / n;
        int ans = 0;
        while (k > 1 && k % 2 == 0)
            k /= 2, ans++;
        while (k > 1 && k % 3 == 0)
            k /= 3, ans++;
        if (k != 1)
            printf("-1\n");
        else
            printf("%d\n", ans);
    } else {
        printf("-1\n");
    }
    return 0;
}
