#include <bits/stdc++.h>
// LLONG_MIN LLONG_MAX INT_MIN INT_MAX

// const long double pi = M_PI;
#define pi atan(1) * 4

using namespace std;

#define INF 1e9

#define DEBUG 0

typedef struct data {
    int x, y;
    long double s;
    int idx;
} Data;

bool cmp(Data a, Data b)
{
    return a.s < b.s;
}

int main()
{
    int n;
    scanf("%d", &n);

    Data inp[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &inp[i].x, &inp[i].y);
        inp[i].s = atan2(inp[i].y, inp[i].x) + pi;
        inp[i].idx = i + 1;
    }

    sort(inp, inp + n, cmp);

#if DEBUG
    for (int i = 0; i < n; i++)
        printf("%d %d %.15f %d\n", inp[i].x, inp[i].y, inp[i].s, inp[i].idx);
#endif

    long double ans = 1e9;
    int ans1 = -1, ans2 = -1;

    for (int i = 1; i < n; i++) {
        long double diff = inp[i].s - inp[i - 1].s;
        diff = min(diff, 2 * pi - diff);
#if DEBUG
        printf("%.15Lf %.15Lf\n", diff, ans);
#endif

        if (diff < ans) {
            ans = diff;
            ans1 = inp[i].idx;
            ans2 = inp[i - 1].idx;
#if DEBUG
            printf("%d %d\n", ans1, ans2);
#endif
        }
    }

    long double diff = inp[n - 1].s - inp[0].s;
    diff = min(diff, 2 * pi - diff);

    if (diff < ans)
        printf("%d %d\n", inp[0].idx, inp[n - 1].idx);
    else
        printf("%d %d\n", ans1, ans2);

    return 0;
}
