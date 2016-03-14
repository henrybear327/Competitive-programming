#include <cstdio>
#include <algorithm>

using namespace std;

typedef struct coor {
    int x, y;
    int type;
} Coor;

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while (ncase--) {
        int n;
        scanf("%d", &n);

        char input[100];
        int map[10][10];
        for (int i = 0; i < n; i++) {
            scanf("%s", input);
            for (int j = 0; j < n; j++) {
                if (input[j] == '.')
                    map[i][j] = 0;
                else if (input[j] == '1')
                    map[i][j] = 1;
                else
                    map[i][j] = 2;
            }
        }

        // determine no solution ( down -> right -> up -> left)
        int idx = 0;
        Coor seq[4] = {0, 0, 0};
        for (int i = 0; i < n; i++) {
            if (map[i][0] == 1 || map[i][0] == 2) {
                seq[idx].type = map[i][0];
                seq[idx].x = i;
                seq[idx++].y = 0;
            }
        }

        for (int i = 1; i < n; i++) {
            if (map[n - 1][i] == 1 || map[n - 1][i] == 2) {
                seq[idx].type = map[n - 1][i];
                seq[idx].x = n - 1;
                seq[idx++].y = i;
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            if (map[i][n - 1] == 1 || map[i][n - 1] == 2) {
                seq[idx].type = map[i][n - 1];
                seq[idx].x = i;
                seq[idx++].y = n - 1;
            }
        }

        for (int i = n - 2; i >= 1; i--) {
            if (map[0][i] == 1 || map[0][i] == 2) {
                seq[idx].type = map[0][i];
                seq[idx].x = 0;
                seq[idx++].y = i;
            }
        }

        if (n == 1 || (seq[0].type != seq[1].type && seq[3].type != seq[0].type)) {
            // n == 1 this case doesn't matter
            printf("-1\n");
            continue;
        }

        // get distance
        int ans = 0;
        if (seq[0].type == seq[1].type) {
            ans += (abs(seq[0].x - seq[1].x) + abs(seq[0].y - seq[1].y));
            ans += (abs(seq[2].x - seq[3].x) + abs(seq[2].y - seq[3].y));
        } else {
            ans += (abs(seq[0].x - seq[3].x) + abs(seq[0].y - seq[3].y));
            ans += (abs(seq[1].x - seq[2].x) + abs(seq[1].y - seq[2].y));
        }

        int cntx = 0, cnty = 0;
        for (int i = 0; i < 3; i++) {
            if (seq[i].x == seq[i + 1].x)
                cntx++;
            if (seq[i].y == seq[i + 1].y)
                cnty++;
        }

        if (cntx == 3 || cnty == 3)
            printf("%d\n", ans + 4);
        else
            printf("%d\n", ans + 2);
    }

    return 0;
}
