#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
struct Data {
    int idx;
    ii inp;
};

void solve()
{
    int n;
    scanf("%d", &n);

    Data events[n];
    for (int i = 0; i < n; i++) {
        events[i].idx = i;
        scanf("%d %d", &events[i].inp.first, &events[i].inp.second);
    }
    sort(events, events + n, [](const Data &a, const Data &b) {
        if (a.inp.first == b.inp.first)
            return a.inp.second < b.inp.second;
        return a.inp.first < b.inp.first;
    });

    int nextAvailable[2] = {0};
    char ans[n + 3] = {'\0'};
    for (const auto &event : events) {
        // printf("%d %d %d\n", event.idx, event.inp.first, event.inp.second);

        bool ok = false;
        for (int i = 0; i < 2; i++) {
            if (nextAvailable[i] <= event.inp.first) {
                if (i == 0)
                    ans[event.idx] = 'C';
                else
                    ans[event.idx] = 'J';
                ok = true;

                nextAvailable[i] = event.inp.second;
                break;
            }
        }

        if (ok == false) {
            printf("IMPOSSIBLE");

            return;
        }
    }

    printf("%s", ans);
}

int main()
{
    int ncase;
    scanf("%d", &ncase);

    for (int i = 1; i <= ncase; i++) {
        printf("Case #%d: ", i);
        solve();
        printf("\n");
    }

    return 0;
}
