#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

void solve()
{
    int p, s;
    scanf("%d %d", &p, &s);
    
    double tmp = p * p - 24 * s;
    tmp = sqrt(tmp);
    
    double x1 = (p + tmp) / 12;
    double x2 = (p - tmp) / 12;
    
    double z1 = 1.0 * p / 4 - 2 * x1;
    double z2 = 1.0 * p / 4 - 2 * x2;
    
    printf("%.2f\n", max(x1 * x1 * z1, x2 * x2 * z2));
}
int main()
{
    int ncase;
    scanf("%d", &ncase);

    while (ncase--) {
        solve();
    }

    return 0;
}
