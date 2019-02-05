#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

struct Line {
    int a, b;
    bool checkGreater;
};

int main()
{
    int n, d;
    scanf("%d %d", &n, &d);

    Line line[4];
    line[0] = {1, d, false};          // y = x + d, >
    line[1] = {-1, 2 * n - d, false}; // y = -x + (2n - d), <
    line[2] = {1, -d, true};          // y = x - d, <
    line[3] = {-1, d, true};          // y = -x + d, >

    int q;
    scanf("%d", &q);
    while (q--) {
        int x, y;
        scanf("%d %d", &x, &y);

        bool in = true;
        for (int i = 0; i < 4; i++) {
            int y1 = line[i].a * x + line[i].b;
            if (line[i].checkGreater && y1 <= y) {
            } else if (line[i].checkGreater == false && y1 >= y) {
            } else {
                in = false;
            }
        }

        printf("%s\n", in ? "YES" : "NO");
    }

    return 0;
}
