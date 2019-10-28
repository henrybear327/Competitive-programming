#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const double PI = atan(1) * 4.0;

int main()
{
    int a, b, x;
    scanf("%d %d %d", &a, &b, &x);

    int total = a * a * b;

    double ans = 0.0;
    // case 1
    double z = (2.0 * (total - x)) / (1.0 * a * a);
    if (z <= b) {
        // printf("z1 = %.15lf, ans = %.15lf\n", z, ans);
        ans = atan(z / a);
    } else {
        // case 2
        z = (2.0 * x) / (1.0 * b * a);
        ans = PI / 2 - atan(z / (1.0 * b));
        // printf("z2 = %.15lf, ans = %.15lf\n", z, ans);
    }

    printf("%.15lf\n", ans * 180.0 / PI);

    return 0;
}
