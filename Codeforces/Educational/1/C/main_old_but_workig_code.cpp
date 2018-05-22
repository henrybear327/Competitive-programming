/*
AC if you use long double

WTF
*/

#include <bits/stdc++.h>
// LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#define PI (atan(1) * 4)

#define double long double

using namespace std;

#define INF 1e9

inline double atan2_process(double x, double y)
{
    double ans = atan2(y, x);
    if (ans < 0.0)
        ans += 2 * PI;

    return ans;
}

inline double get_small_angle(double x)
{
    return x > PI ? 2 * PI - x : x;
}

typedef struct data {
    int x, y;
    double s;
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
        inp[i].s = atan2_process(inp[i].x, inp[i].y);
        inp[i].idx = i + 1;
    }

    sort(inp, inp + n, cmp);

    /*
    for (int i = 0; i < n; i++)
        printf("%d %d %f %d\n", inp[i].x, inp[i].y, inp[i].s, inp[i].idx);
    */

    double ans = INF;
    int ans1 = -1, ans2 = -1;
    for (int i = 1; i < n; i++) {
        if (get_small_angle(inp[i].s - inp[i - 1].s) < ans) {
            ans = get_small_angle(inp[i].s - inp[i - 1].s);
            ans1 = inp[i - 1].idx;
            ans2 = inp[i].idx;
        }
    }

    if (get_small_angle(inp[n - 1].s - inp[0].s) < ans)
        printf("%d %d\n", inp[n - 1].idx, inp[0].idx);
    else
        printf("%d %d\n", ans1, ans2);

    return 0;
}
