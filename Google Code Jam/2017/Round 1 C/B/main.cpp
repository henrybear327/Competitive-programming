#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef pair<int, ii> gapi;

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while (ncase--) {
        int a, b;
        scanf("%d %d", &a, &b);

        int atime = 0, btime = 0;
        vector<iii> inp;
        for (int i = 0; i < a; i++) {
            int s, t;
            scanf("%d %d", &s, &t);

            inp.push_back(iii(ii(s, t), 1));
            btime += (t - s);
        }

        for (int i = 0; i < b; i++) {
            int s, t;
            scanf("%d %d", &s, &t);

            inp.push_back(iii(ii(s, t), 2));
            atime += (t - s);
        }

        sort(inp.begin(), inp.end());

        vector<gapi> gap;
        int ans = 0;
        for (int i = 0; i < (int)inp.size(); i++) {
            int sz = (int)inp.size();
            int s1 = inp[(i - 1 + sz) % sz].first.first;
            int t1 = inp[(i - 1 + sz) % sz].first.second;
            int type1 = inp[(i - 1 + sz) % sz].second;

            int s2 = inp[i].first.first;
            int t2 = inp[i].first.second;
            int type2 = inp[i].second;

            if ((s2 == t1) || (s2 == 0 && t1 == 1440)) {
                if (type1 != type2)
                    ans++;
                continue;
            }

            // printf("%d %d %d %d\n", s1, t1, s2, t2);
            // printf("diff %d\n",  (s2 - t1) > 0 ? (s2 - t1) : 1440 - abs(s2 - t1));
            gap.push_back(gapi((s2 - t1) > 0 ? (s2 - t1) : 1440 - abs(s2 - t1),
                               ii(type1, type2)));
        }
        // printf("%d\n", ans);

        sort(gap.begin(), gap.end());
        reverse(gap.begin(), gap.end());
        // for(auto i : gap)
        // printf("%d %d %d\n", i.first, i.second.first, i.second.second);
        for (int i = (int)gap.size() - 1; i >= 0; i--) {
            bool ok = false;
            if (gap[i].second.first == gap[i].second.second) {
                int diff = gap[i].first;
                if (gap[i].second.first == 1) {
                    if (btime + diff <= 720) {
                        btime += diff;
                        ok = true;
                    }
                } else {
                    if (atime + diff <= 720) {
                        atime += diff;
                        ok = true;
                    }
                }

                if (ok == false)
                    ans += 2;
            } else {
                ans++;
            }
            gap.pop_back();
        }

        printf("Case #%d: %d\n", 100 - ncase, ans);
    }

    return 0;
}
