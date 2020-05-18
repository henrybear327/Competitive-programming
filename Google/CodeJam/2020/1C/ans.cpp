#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAXN = 20000;

int N, D;
LL A[MAXN];
bool mark[MAXN];

LL gcd(LL a, LL b)
{
    while (a && b)
        if (a > b) a %= b; else b %= a;
    return a + b;
}

int main()
{
    int T; scanf("%d", &T);
    for (int t = 0; t < T; ++t) {
        printf("Case #%d: ", t + 1);

        scanf("%d%d", &N, &D);
        for (int i = 0; i < N; ++i)
            scanf("%lld", &A[i]);
        sort(A, A + N);

        map<pair<LL, LL>, vector<pair<int, int> > > cnts;
        for (int i = 0; i < N; ++i)
            for (int d = 1; d <= D; ++d) {
                LL g = gcd(A[i], d);
                cnts[{A[i]/g, d/g}].push_back({d, i});
            }

        int answer = 1000000000;

        for (auto& q : cnts) {
            auto& s = q.first;
            auto& cur = q.second;
            sort(begin(cur), end(cur));

            // printf("%lld/%lld\n", s.first, s.second);
            // for (int i = 0; i < cur.size(); ++i)
            //     printf(" %d(%d)", cur[i].first, cur[i].second);
            // printf("\n");

            int res = 0, left = D;
            for (auto& r : cur) {
                mark[r.second] = true;
                if (left >= r.first) {
                    res += r.first - 1;
                    left -= r.first;
                } else {
                    res += left;
                    left = 0;
                    break;
                }
            }
            if (left > 0) {
                for (int i = N - 1; i >= 0; --i)
                    if (!mark[i]) {
                        LL z = (s.second * A[i]) / s.first;
                        if (z == 0) break;
                        res += min(z, (LL)left);
                        left -= min(z, (LL)left);
                        if (left == 0) break;
                    }
            }
            for (auto& r : cur)
                mark[r.second] = false;

            if (left == 0)
                answer = min(res, answer);
        }

        printf("%d\n", answer);
    }
    return 0;
}
