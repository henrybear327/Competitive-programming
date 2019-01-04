#include <bits/stdc++.h>

using namespace std;

int main()
{
    int d, h, v, e;
    scanf("%d %d %d %d", &d, &h, &v, &e);

    double r = d / 2.0;
    double origV = r * r * acos(-1) * h;

    double dRate = r * r * acos(-1) * e;

    if(v > dRate) {
        printf("YES\n");

        double ans = (origV) / (v - dRate);

        printf("%.15f\n", ans);
    } else {
        printf("NO\n");
    }

    return 0;
}