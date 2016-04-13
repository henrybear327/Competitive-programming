#include <cstdio>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    int n, m;
    while (scanf("%d %d", &n, &m) == 2) {
        getchar();
        vector<pair<int, int>> p;

        int maxn[10000] = {0};
        int minn[10000];
        for (int i = 0; i < 10000; i++)
            minn[i] = INT_MAX;

        int l = INT_MAX, r = 0;
        for (int i = m; i >= 1; i--) {
            char input[10000];
            fgets(input, 10000, stdin);
            for (int j = 0; j < n; j++) {
                if (input[j] - '0' == 1) {
                    // j + 1, i
                    maxn[j + 1] = max(maxn[j + 1], i);
                    minn[j + 1] = min(minn[j + 1], i);

                    l = min(j + 1, l);
                    r = max(j + 1, r);
                }
            }
        }

        for (int i = l; i <= r; i++) {
            if (minn[i] != INT_MAX) {
                if (maxn[i] == minn[i])
                    p.push_back(make_pair(i, maxn[i]));
                else {
                    p.push_back(make_pair(i, maxn[i]));
                    p.push_back(make_pair(i, minn[i]));
                }
            }
        }

        double ans = 0;
        for (int i = 0; i < (int)p.size(); i++) {
            // printf("%d %d\n", p[i].first, p[i].second);
            for (int j = i + 1; j < (int)p.size(); j++) {
                double dx = p[j].first - p[i].first;
                double dy = p[j].second - p[i].second;

                double curr = round(sqrt(dx * dx + dy * dy));
                ans = max(curr, ans);
            }
        }

        printf("%.0f\n", ans);
    }

    return 0;
}
