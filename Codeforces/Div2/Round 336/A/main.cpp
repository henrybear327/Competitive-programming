#include <bits/stdc++.h>
// LLONG_MIN LLONG_MAX INT_MIN INT_MAX

using namespace std;

int main()
{
    int n, s;
    scanf("%d %d", &n, &s);

    int max_time[s + 1];
    memset(max_time, 0, sizeof(max_time));

    for (int i = 0; i < n; i++) {
        int f, t;
        scanf("%d %d", &f, &t);

        max_time[f] = max(max_time[f], t);
    }

    int ans = 0;
    for (int i = s; i > 0; i--) {
        if (ans >= max_time[i]) {
            ans++;
        } else {
            ans = max_time[i] + 1;
        }
    }
    printf("%d\n", ans);

    return 0;
}
