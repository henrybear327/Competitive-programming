#include <bits/stdc++.h>
// LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    pair<int, int> data[100010];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &data[i].first, &data[i].second);
    }

    int max_so_far = data[0].second;
    int ans = data[0].first * max_so_far;
    for (int i = 1; i < n; i++) {
        if (data[i].second >= max_so_far) {
            ans += (data[i].first * max_so_far);
        } else {
            max_so_far = data[i].second;
            ans += data[i].first * max_so_far;
        }
    }

    printf("%d\n", ans);

    return 0;
}
