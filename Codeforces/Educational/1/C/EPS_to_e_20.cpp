#include <bits/stdc++.h>
// LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#define PI (atan(1) * 4)

using namespace std;

#define INF 1e9
#define EPS 1e-20 //1e-17 will got AC, 1e-16 will get WA
#define double long double

inline double atan2_process(double x, double y)
{
    double ans = atan2(y, x);
    if (ans < EPS)
        ans += 2 * PI;

    return ans;
}

inline double get_small_angle(double x)
{
    return (x - PI > -EPS ? 2 * PI - x : x);
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
        printf("%d %d %.15f %d\n", inp[i].x, inp[i].y, inp[i].s, inp[i].idx);
    */

    double ans = get_small_angle(inp[1].s - inp[0].s);
    int ans1 = inp[0].idx, ans2 = inp[1].idx;
    for (int i = 2; i < n; i++) {
        /*
        printf("before %.15f %.15f\n", get_small_angle(inp[i].s - inp[i - 1].s),
               ans);
        printf("diff\n%.18f\n%.18f\n", ans - get_small_angle(inp[i].s - inp[i -
        1].s), 1e-9);
        */
        if (ans - get_small_angle(inp[i].s - inp[i - 1].s) > -EPS) {
            ans = get_small_angle(inp[i].s - inp[i - 1].s);
            ans1 = inp[i - 1].idx;
            ans2 = inp[i].idx;
        }
        /*
        printf("after  %.15f %.15f\n", get_small_angle(inp[i].s - inp[i - 1].s),
               ans);
        */
    }

    if (ans - get_small_angle(inp[n - 1].s - inp[0].s) > -EPS)
        printf("%d %d\n", inp[n - 1].idx, inp[0].idx);
    else
        printf("%d %d\n", ans1, ans2);

    return 0;
}
