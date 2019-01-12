#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

struct Point {
    int first, second, orig;
};

void solve()
{
    int n;
    scanf("%d", &n);

    Point inp[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &inp[i].first, &inp[i].second);
        inp[i].orig = i;
    }

    sort(inp, inp + n, [](const Point a, const Point b) {
        if (a.first == b.first)
            return a.second > b.second;
        return a.first < b.first;
    });
    // when starting point is the same, the furthest ending point goes first, o.w.
    // [2,4] [2,5] we will be fucked

    int r = inp[0].second;
    bool ok = false;
    for (int i = 1; i < n; i++) {
        if (r < inp[i].first) {
            ok = true;
            break;
        } else {
            r = max(r, inp[i].second);
        }
    }

    // come on bro, they asked you to mark the ORIGINAL sequence...
    int ans[n];
    if (ok) {
        for (int i = 0; i < n; i++)
            if (inp[i].second <= r)
                ans[inp[i].orig] = 1;
            else
                ans[inp[i].orig] = 2;
        for (auto i : ans)
            printf("%d ", i);
        printf("\n");
    } else {
        printf("-1\n");
    }
}

int main()
{
    int q;
    scanf("%d", &q);

    for (int i = 0; i < q; i++) {
        solve();
    }

    return 0;
}
