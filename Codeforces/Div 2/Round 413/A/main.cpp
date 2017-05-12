#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, t, k, d;
    scanf("%d %d %d %d", &n, &t, &k, &d);

    int times = (n / k) + (n % k == 0 ? 0 : 1);

    int ans1 = t * times;

    int ans2 = 0;
    int t1 = 0, t2 = d;
    for (int i = 0; i < times; i++) {
        if (t1 <= t2) {
            t1 += t;
        } else {
            t2 += t;
        }
    }
    ans2 = max(t1, t2);

    printf("%s\n", ans1 <= ans2 ? "NO" : "YES");

    return 0;
}
