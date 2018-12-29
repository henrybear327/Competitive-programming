#include <bits/stdc++.h>
// LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

#define PI atan(1) * 4

#define DEBUG 0

using namespace std;

typedef long long ll;
double get_h(double PA, double AB, double BP)
{
#if DEBUG == 1
    printf("%f %f %f\n", PA, AB, BP);
#endif
    // bad triangle
    if ((PA + AB < BP) || (AB + BP < PA)) {
        return -1;
    }

    PA = sqrt(PA);
    AB = sqrt(AB);
    BP = sqrt(BP);
    double s = (PA + AB + BP) / 2;
    double area = sqrt(s * (s - PA) * (s - AB) * (s - BP));
#if DEBUG == 1
    printf("%f %f %f\n", PA, AB, BP);
    printf("area %f %f\n", area, area * 2 / AB);
#endif
    return area * 2 / AB;
}

int main()
{
    int n;
    long long int x, y;
    scanf("%d %lld %lld", &n, &x, &y);

    pair<long long int, long long int> inp[100010];
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld", &inp[i].first, &inp[i].second);
    }

    long long int dist[100010];
    for (int i = 0; i < n; i++) {
        long long int dx = inp[i].first - x;
        long long int dy = inp[i].second - y;

        dist[i] = dx * dx + dy * dy;
    }

    long long int dist_ab[100010];
    for (int i = 0; i < n; i++) {
        long long int dx = inp[i].first - inp[(i + 1) % n].first;
        long long int dy = inp[i].second - inp[(i + 1) % n].second;

        dist_ab[i] = dx * dx + dy * dy;
    }

    long long int r = LLONG_MAX, R = LLONG_MIN;

    for (int i = 0; i < n; i++) {
        if (dist[i] > R) {
            R = dist[i];
        }
    }

    for (int i = 0; i < n; i++) {
        if (dist[i] < r) {
            r = dist[i];
        }
    }

    // get h
    double r_ans = sqrt(r);
    for (int i = 0; i < n; i++) {
        double h = get_h(dist[i], dist_ab[i], dist[(i + 1) % n]);
#if DEBUG == 1
        printf("i = %d, %f\n", i, h);
#endif
        if (h == -1)
            continue;
        else
            r_ans = min(r_ans, h);
    }

    r_ans *= r_ans;
#if DEBUG == 1
    printf("%f %f\n", (double)R, (double)r_ans);
#endif
    printf("%.15f\n", (double)(R - r_ans) * PI);

    return 0;
}
