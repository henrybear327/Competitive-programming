#include <cstdio>
#include <queue>

using namespace std;

typedef struct _data {
    int idx, time, ans;
    char side[10];
} Data;

int main()
{
    int cases;
    scanf("%d", &cases);
    while (cases--) {
        int n, t, query;
        scanf("%d %d %d", &n, &t, &query);

        Data inp[query];
        queue<Data> l, r;
        for (int i = 0; i < query; i++) {
            inp[i].idx = i;
            scanf("%d %s", &inp[i].time, inp[i].side);

            if (inp[i].side[0] == 'l')
                l.push(inp[i]);
            else
                r.push(inp[i]);
        }

        int now = 0;
        bool at_left = true;
        while (!l.empty() || !r.empty()) {
            if (at_left && !l.empty() && l.front().time <= now) {
                for (int i = 0; i < n && !l.empty() && l.front().time <= now; i++) {
                    inp[l.front().idx].ans = now + t;
                    l.pop();
                }
            } else if (!at_left && !r.empty() && r.front().time <= now) {
                for (int i = 0; i < n && !r.empty() && r.front().time <= now; i++) {
                    inp[r.front().idx].ans = now + t;
                    r.pop();
                }
            } else if (at_left) {
                if (!l.empty() && !r.empty()) {
                    if (l.front().time <= r.front().time) {
                        now = now > l.front().time ? now : l.front().time;
                        // be aware of this condition. It may overwrite the bigger "now"
                        // time with the smaller front().time time
                        continue;
                    } else
                        now = now > r.front().time ? now : r.front().time;
                } else if (!l.empty()) {
                    now = now > l.front().time ? now : l.front().time;
                    continue;
                } else {
                    now = now > r.front().time ? now : r.front().time;
                }
            } else {
                if (!l.empty() && !r.empty()) {
                    if (r.front().time <= l.front().time) {
                        // now = r.front().time - t; // wrong because it will change
                        // direction in the end, too!
                        now = now > r.front().time ? now : r.front().time;
                        continue;
                    } else
                        // can't just change back to the left shore,
                        now = now > l.front().time ? now : l.front().time;
                    // must wait until the next car to appear
                } else if (!r.empty()) {
                    now = now > r.front().time ? now : r.front().time;
                    continue;
                } else {
                    now = now > l.front().time ? now : l.front().time;
                }
            }

            now += t;
            at_left = !at_left;
        }

        for (int i = 0; i < query; i++) {
            printf("%d\n", inp[i].ans);
        }
        if (cases)
            printf("\n");
    }

    return 0;
}
