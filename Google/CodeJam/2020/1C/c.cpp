#include <bits/stdc++.h>

/*
With Andy!

1
5 5
5 6 7 8 9

GCJ Test case is not strong enough, we can get AC with wrong code
*/
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const double EPS = 1e-9;
bool isSame(double a, double b)
{
    return abs(a - b) < EPS;
}

void solve()
{
    int n, d;
    scanf("%d %d", &n, &d);

    double inp[n];
    ll orig[n];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &orig[i]);
        inp[i] = orig[i];
    }

    sort(inp, inp + n);
    sort(orig, orig + n);
    int ans = INT_MAX;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) {
            double target = inp[i] / (j + 1);
            int cnt = j + 1;
            int cut = j;

            if (cnt >= d) {
                ans = min(ans, cut);
                continue;
            }

            auto go = [&](int k) {
                while (inp[k] - target > -EPS) { // inp[k] > target
                    //     printf("%f %f\n", inp[k], target);
                    if (isSame(inp[k], target)) {
                        cnt++;
                        inp[k] = 0;
                    } else {
                        inp[k] -= target;
                        cnt++;
                        cut++;
                    }

                    if (cnt >= d) {
                        ans = min(ans, cut);
                        break;
                    }
                }
            };

            bool seen[n] = {false};
            for (int k = 0; k < n; k++) {
                if (k == i)
                    continue;
                if (cnt >= d) {
                    ans = min(ans, cut);
                    continue;
                }

                ll quotient = orig[k] / target;
                if (isSame(target * quotient, orig[k])) {
                    seen[k] = true;
                    go(k);
                }
            }

            for (int k = 0; k < n; k++) {
                if (k == i)
                    continue;
                if (cnt >= d) {
                    ans = min(ans, cut);
                    continue;
                }

                if (seen[k] == false)
                    go(k);
            }

            for (int k = 0; k < n; k++)
                inp[k] = orig[k];
        }
    }

    printf("%d\n", ans);
}

int main()
{
    int ncase;
    scanf("%d", &ncase);

    for (int i = 1; i <= ncase; i++) {
        printf("Case #%d: ", i);
        solve();
    }

    return 0;
}
