#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

#define EPS 1e-8

/* Wrong
3 10 3 2
1 5
2 2
2 8
*/

int main()
{
    ll n, w, v, u;
    scanf("%lld %lld %lld %lld", &n, &w, &v, &u); // special case n = 1

    ii inp[10010];
    int mny = INT_MAX;

    bool hasneg = false;
    int neg = 0;
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        inp[i] = ii(x, y);

        if (x < 0) {
            hasneg = true;
            neg++;
        }

        mny = min(mny, inp[i].second);
    }

    bool ok = true;
    for (int i = 0; i < n; i++) {
        double tv = (double)inp[i].first / v;
        double tu = (double)inp[i].second / u;

        if (tu - tv > EPS) {
            ok = false;
            break;
        }
    }

    if (ok && hasneg == false) {
        printf("%.15f\n", (double)w / u);
    } else if (neg == n) {
        printf("%.15f\n", (double)w / u);
    } else {
        // right most low point
        int mnx = -1, idx;
        for (int i = 0; i < n; i++) {
            if (inp[i].second == mny) {
                mnx = inp[i].first;
                idx = i;
            }
            if (inp[i].second != mny && mnx != -1)
                break;
        }

        if (mnx < 0) {
            for (int i = idx; i < n; i++) {
                if (inp[i].first >= 0) {
                    mnx = inp[i].first;
                    mny = inp[i].second;
                    idx = i;
                    break;
                }
            }
        }

        double ans = 0;
        int prev = -1, lastx = -1;
        for (int i = idx; i < n; i++) {
            if (inp[i].first > lastx) {
                if (prev == -1) {
                    double tu = (double)inp[i].second / u;
                    double tv = (double)inp[i].first / v;

                    if (tu >= tv)
                        ans += tu;
                    else
                        ans += tv;
                } else {
                    double dx = inp[i].first - inp[prev].first;
                    double dy = inp[i].second - inp[prev].second;

                    double tu = dy / u;
                    double tv = dx / v;

                    if (tu >= tv)
                        ans += tu;
                    else
                        ans += tv;
                }
                prev = i;
                lastx = inp[i].first;
            } else if (inp[i].first < lastx) {
                // go to top
                double dy = w - inp[prev].second;
                ans += dy / u;
                break;
            }
        }

        printf("%.15f\n", ans);
    }

    return 0;
}
