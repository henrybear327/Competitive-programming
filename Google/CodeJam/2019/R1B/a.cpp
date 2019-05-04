#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

const int N = 100010;
void solve()
{
    int p, q;
    scanf("%d %d", &p, &q);

    ii xa[N], ya[N];
    for (int i = 0; i < N; i++) {
        xa[i] = ii{0, 0};
        ya[i] = ii{0, 0};
    }

    for (int i = 0; i < p; i++) {
        int x, y;
        char dir;
        scanf("%d %d %c", &x, &y, &dir);

        if (dir == 'N') { // y++
            if (y + 1 <= q) {
                // y.push_back(ii{y + 1, q});
                ya[y + 1].first++;
                ya[q].second++;
                // x.push_back(ii{0, q});
                xa[0].first++;
                xa[q].second++;
            }
        } else if (dir == 'S') { // y--
            if (y - 1 >= 0) {
                // y.push_back(ii{0, y - 1});
                ya[0].first++;
                ya[y - 1].second++;
                // x.push_back(ii{0, q});
                xa[0].first++;
                xa[q].second++;
            }
        } else if (dir == 'E') { // x++
            if (x + 1 <= q) {
                // x.push_back(ii{x + 1, q});
                xa[x + 1].first++;
                xa[q].second++;
                // y.push_back(ii{0, q});
                ya[0].first++;
                ya[q].second++;
            }
        } else { // 'W' // x--
            if (x - 1 >= 0) {
                // x.push_back(ii{0, x - 1});
                xa[0].first++;
                xa[x - 1].second++;
                // y.push_back(ii{0, q});
                ya[0].first++;
                ya[q].second++;
            }
        }
    }

    int x = 0, y = 0;
    {
        int cnt = 0;
        int mx = 0;
        for (int i = 0; i < N; i++) {
            cnt += xa[i].first;
            if (mx < cnt) {
                mx = cnt;
                x = i;
            }
            cnt -= xa[i].second;
        }
    }
    {
        int cnt = 0;
        int mx = 0;
        for (int i = 0; i < N; i++) {
            cnt += ya[i].first;
            if (mx < cnt) {
                mx = cnt;
                y = i;
            }
            cnt -= ya[i].second;
        }
    }

    printf("%d %d\n", x, y);
}

int main()
{
    int ncase;
    scanf("%d", &ncase);
    for (int i = 1; i <= ncase; i++) {
        printf("Case #%d: ", i);
        solve();
    }
}
