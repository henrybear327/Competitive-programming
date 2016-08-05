#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

#define EPS 1e-9

int main()
{
    int n, w, v, u;
    scanf("%d %d %d %d", &n, &w, &v, &u);

    vector<ii> inp;

    double m = (double)u / v;
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        inp.push_back(ii(x, y));
    }

    int wrongSide = 0;
    for (int i = 0; i < n; i++) {
        // printf("%d %d\n", inp[i].first, inp[i].second);
        // printf("%f %f\n", m * inp[i].first, m * inp[i].first - inp[i].second);
        if (m * inp[i].first - inp[i].second > -EPS)
            continue;
        else
            wrongSide++;
    }

    if (wrongSide == 0 || wrongSide == n) {
        printf("%.15f\n", (double)w / u);
    } else {
        double b = INT_MAX;

        for (int i = 0; i < n; i++) {
            b = min(b, inp[i].second - inp[i].first * m);
        }

        printf("%.15f\n", fabs((w - b) / u));
    }

    return 0;
}
