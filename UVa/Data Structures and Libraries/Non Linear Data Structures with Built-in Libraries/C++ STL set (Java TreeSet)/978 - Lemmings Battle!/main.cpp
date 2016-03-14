#include <cstdio>
#include <queue>
#include <cstdlib>
#include <set>
#include <vector>

using namespace std;

int main()
{
    int cases;
    scanf("%d", &cases);
    while (cases--) {
        int field, green, blue;
        scanf("%d %d %d", &field, &green, &blue);

        multiset<int, greater<int>> g;
        multiset<int, greater<int>> b;

        for (int i = 0; i < green; i++) {
            int tmp;
            scanf("%d", &tmp);

            g.insert(tmp);
        }

        for (int i = 0; i < blue; i++) {
            int tmp;
            scanf("%d", &tmp);

            b.insert(tmp);
        }

        while (!g.empty() && !b.empty()) {
            auto ib = b.begin();
            auto ig = g.begin();

            vector<pair<bool, int>> fq;
            int cnt = field;
            for (int i = 0; i < field; i++) {
                if (b.empty() || g.empty()) {
                    cnt = i;
                    break;
                }

                int bb = *ib;
                ib = b.erase(ib);
                int gg = *ig;
                ig = g.erase(ig);

                bool flag;
                if (bb > gg) {
                    flag = true;
                } else {
                    flag = false;
                }

                fq.push_back(make_pair(flag, abs(bb - gg)));
            }

            for (int i = 0; i < cnt; i++) {
                if (fq[i].second) {
                    if (fq[i].first)
                        b.insert(fq[i].second);
                    else
                        g.insert(fq[i].second);
                }
            }
        }

        if (g.empty() && b.empty()) {
            printf("green and blue died\n");
        } else if (g.empty()) {
            printf("blue wins\n");
            auto ib = b.begin();
            while (!b.empty()) {
                printf("%d\n", *ib);
                ib = b.erase(ib);
            }
        } else {
            printf("green wins\n");
            auto ig = g.begin();
            while (!g.empty()) {
                printf("%d\n", *ig);
                ig = g.erase(ig);
            }
        }

        if (cases)
            printf("\n");
    }

    return 0;
}
