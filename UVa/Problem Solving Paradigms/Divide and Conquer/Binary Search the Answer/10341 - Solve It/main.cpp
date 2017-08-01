#include <bits/stdc++.h>

using namespace std;

double p, q, r, s, t, u;
double val(double x)
{
    return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

#define EPS 1e-10

int main()
{
    while (scanf("%lf %lf %lf %lf %lf %lf", &p, &q, &r, &s, &t, &u) == 6) {
        double ll = 0, rr = 1;
        for (int i = 0; i < 100; i++) {
            double mid = (ll + rr) / 2;

            if (val(mid) < 0)
                rr = mid;
            else
                ll = mid;
        }

        if (fabs(val(ll)) < EPS)
            printf("%.4f\n", ll);
        else
            printf("No solution\n");
    }

    return 0;
}
