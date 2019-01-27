#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const double PI = 2 * acos(0);

int main()
{
    int n, r;
    scanf("%d %d", &n, &r);

    double x = cos(1.0 * 90 * (n - 2) / n / 180 * PI);
    printf("%.15f\n", x * r / (1 - x));

    return 0;
}
