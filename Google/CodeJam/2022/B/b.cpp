#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

set<ii> data1, data2;

bool inbound(int x)
{
    return 0 <= x && x < 205;
}

void draw_circle_filled(int r)
{
    for (int x = -r; x <= r; x++) {
        for (int y = -r; y <= r; y++) {
            if ((int)round(sqrt(x * x + y * y)) <= r) {
                data1.insert({x, y});
            }
        }
    }
}

void draw_circle_parimeter(int r)
{
    for (int x = -r; x <= r; x++) {
        int y = round(sqrt(r * r - x * x));
        data2.insert({x, y});
        data2.insert({x, -y});
        data2.insert({y, x});
        data2.insert({-y, x});
    }
}

void solve()
{
    data1.clear();
    data2.clear();

    int r;
    scanf("%d", &r);

    draw_circle_filled(r);

    for (int i = 0; i <= r; i++) {
        draw_circle_parimeter(i);
    }

    set<ii> tmp;
    for (auto i : data1) {
        if (data2.find(i) != data2.end()) {
            data2.erase(i);
        } else {
            tmp.insert(i);
        }
    }

    printf("%d\n", (int)(tmp.size() + data2.size()));
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
