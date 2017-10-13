#include <bits/stdc++.h>

using namespace std;

#define N 111
#define MAX 1e18

typedef long long ll;

struct Pt {
    int x, y;
};

struct Rect {
    Pt upperLeft, lowerRight;
    int k;
};

double dist(int x1, int y1, int x2, int y2)
{
    ll dx = x2 - x1;
    ll dy = y2 - y1;
    return sqrt(dx * dx + dy * dy);
}

void solve()
{
    int n, l, u;
    scanf("%d %d %d", &n, &l, &u);

    // read
    double m[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            m[i][j] = (i == j ? 0 : MAX);

    vector<Rect> rect;
    rect.push_back({{0, 0}, {u, 0}, 0}); // bottom
    rect.push_back({{0, l}, {u, l}, 0}); // top
    m[0][1] = m[1][0] = l;

    for (int i = 0; i < n; i++) {
        int h, w, d, k;
        scanf("%d %d %d %d", &h, &w, &d, &k);

        if (k == 0) {
            Pt upperLeft = {0, h + d};
            Pt lowerRight = {w, d};
            rect.push_back({upperLeft, lowerRight, k});
        } else {
            Pt upperLeft = {u - w, h + d};
            Pt lowerRight = {u, d};
            rect.push_back({upperLeft, lowerRight, k});
        }

        m[i + 2][1] = m[1][i + 2] = l - h - d;
        m[i + 2][0] = m[0][i + 2] = d;
    }

    // build
    int sz = rect.size();
    for (int i = 2; i < sz; i++) {
        for (int j = 2; j < sz; j++) {
            if (i == j)
                continue;

            int &ax = rect[i].upperLeft.x;
            int &ay = rect[i].upperLeft.y;
            int &bx = rect[i].lowerRight.x;
            int &by = rect[i].lowerRight.y;
            int &ki = rect[i].k;

            int &cx = rect[j].upperLeft.x;
            int &cy = rect[j].upperLeft.y;
            int &dx = rect[j].lowerRight.x;
            int &dy = rect[j].lowerRight.y;
            int &kj = rect[j].k;

            double val;
            if (ax <= cx && cx <= bx) { // case1 - 1
                if (ki != kj && cx == bx && by <= cy && cy <= ay) // touching case
                    val = 0;
                else
                    val = min(abs(ay - dy), abs(by - cy));
            } else if (ax <= dx && dx <= bx) { // case1 - 2
                if (ki != kj && dx == bx && by <= dy && dy <= ay) // touching case
                    val = 0;
                else
                    val = min(abs(ay - dy), abs(by - cy));
            } else if (by <= cy && cy <= ay) { // case2 - 1
                val = abs(bx - cx);
            } else if (by <= dy && dy <= ay) { // case2 - 2
                val = abs(bx - cx);
            } else { // case3
                val = min(dist(bx, ay, cx, dy), dist(bx, by, cx, cy));
                /*
                if(ay < dy) {
                    val = dist(bx, ay, cx, dy);
                } else {
                    val = dist(bx, by, cx, cy);
                }
                */
            }

            m[i][j] = min(m[i][j], val);
            m[j][i] = min(m[j][i], val);
            //printf("%d %d %.6f\n", i, j, m[i][j]);
            //printf("%d %d,  %d %d,  %d %d, %d %d\n", ax, ay, bx, by, cx, cy, dx, dy);
        }
    }

    // solve
    for (int k = 0; k < sz; k++)
        for (int i = 0; i < sz; i++)
            for (int j = 0; j < sz; j++) {
                if (m[i][j] > 1e9)
                    continue;
                m[i][j] = min(m[i][j], m[i][k] + m[k][j]);
            }

    printf("%.6f\n", m[0][1]);
}

int main()
{
    freopen("street.in", "r", stdin);

    int ncase;
    scanf("%d", &ncase);

    while (ncase--)
        solve();

    return 0;
}
