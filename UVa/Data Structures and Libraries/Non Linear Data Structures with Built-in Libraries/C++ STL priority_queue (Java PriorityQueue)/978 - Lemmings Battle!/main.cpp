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

        priority_queue<int> g;
        priority_queue<int> b;
        // multiset<int, greater<int>> g;
        // multiset<int, greater<int>> b;

        for (int i = 0; i < green; i++) {
            int tmp;
            scanf("%d", &tmp);

            g.push(tmp);
            // g.insert(tmp);
        }

        for (int i = 0; i < blue; i++) {
            int tmp;
            scanf("%d", &tmp);

            b.push(tmp);
            // b.insert(tmp);
        }

        // auto ib = b.begin();
        // auto ig = g.begin();
        while (!g.empty() && !b.empty()) {
            vector<pair<bool, int>> fq;
            int cnt = field;
            for (int i = 0; i < field; i++) {
                if (b.empty() || g.empty()) {
                    cnt = i;
                    break;
                }

                int bb = b.top();
                // int bb = *ib;
                b.pop();
                // b.erase(ib);
                int gg = g.top();
                // int gg = *ig;
                g.pop();
                // g.erase(ig);

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
                        b.push(fq[i].second);
                    // b.insert(fq[i].second);
                    else
                        g.push(fq[i].second);
                    // g.insert(fq[i].second);
                }
            }
        }

        // ib = b.begin();
        // ig = g.begin();
        if (g.empty() && b.empty()) {
            printf("green and blue died\n");
        } else if (g.empty()) {
            printf("blue wins\n");
            while (!b.empty()) {
                printf("%d\n", b.top());
                b.pop();
                // printf("%d\n", *ib);
                // b.erase(ib);
            }
        } else {
            printf("green wins\n");
            while (!g.empty()) {
                printf("%d\n", g.top());
                g.pop();
                // printf("%d\n", *ig);
                // g.erase(ig);
            }
        }

        if (cases)
            printf("\n");
    }

    return 0;
}
