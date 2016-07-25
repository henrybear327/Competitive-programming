#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

int main()
{
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);

    // c = a * x^(1/3) + b * x^(1/2)
    double l = 0, r = 1e18;
    for(int i = 0; i < 100; i++) {
        double mid = (l + r) / 2;

        double ans = a * pow(mid, 1.0/3.0) + b * pow(mid, 0.5);
        if(ans >= c)
            r = mid;
        else
            l = mid;
    }

    printf("%lld\n", (ll)ceil(l));

    return 0;
}