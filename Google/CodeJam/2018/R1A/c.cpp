#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
const double EPS = 1e-7;
double solve()
{
    int n, p;
    scanf("%d %d\n", &n, &p);

    ii inp[n];
    double sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &inp[i].first, &inp[i].second);
        sum += 2 * (inp[i].first + inp[i].second);
    }

    /* // bug
    for (int i = 0; fabs(sum - (double)p) > EPS && i < n; i++) { // EPS?
        int f = inp[i].first;
        int s = inp[i].second;
        double diagnal = sqrt(f * f + s * s);
        if (fabs(p - sum - 2 * diagnal) < EPS)
            sum += 2 * diagnal;
        else
            return p;
    }
    */
    return sum;
}

int main()
{
    int ncase;
    scanf("%d", &ncase);
    for (int i = 1; i <= ncase; i++) {
        printf("Case #%d: %.15f\n", i, solve());
    }
    return 0;
}
