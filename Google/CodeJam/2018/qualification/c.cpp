#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    scanf("%d", &n);

    int r = 0, c = 0;
    vector<int> x_positions;
    if (n == 20) {
        r = 4;
        c = 5;
        x_positions.push_back(0);
        x_positions.push_back(1);
    } else {
        r = 10;
        c = 20;
        x_positions.push_back(0);
        x_positions.push_back(3);
        x_positions.push_back(6);
        x_positions.push_back(7);
    }

    int m[1111][1111];
    memset(m, 0, sizeof(m));

    int acc = 0;

    int x = 500, y = 500;                       // start trying position
    int upperLeftX = x - 1, upperLeftY = y - 1; // bounding area
    int lowerRightX = upperLeftX + r,
        lowerRightY = upperLeftY + c; // bounding area
    while (1) {
        for (auto i : x_positions) {        // for the area needs to be tried
            for (int j = 0; j < c - 2; j = (j + 3 < c - 2 ? j + 3 : j + 1)) { // for the area needs to be tried
                int currentX = x + i;
                int currentY = y + j;
                
                //fprintf(stderr, "cur X %d cur Y %d\n", currentX, currentY);
                for (int dx = -1; dx <= 1; dx++) {      // surrounding 9 cells
                    for (int dy = -1; dy <= 1; dy++) { // surrounding 9 cells
                        if (m[currentX + dx][currentY + dy] == 0) {
                            printf("%d %d\n", currentX, currentY);
                            //fprintf(stderr, "request X %d Y %d\n", currentX, currentY);
                            fflush(stdout);
                            acc++;

                            goto done;
                        }
                    }
                }
                //fprintf(stderr, "end cur X %d cur Y %d\n", currentX, currentY);
            }
        }
done:
        int retX, retY;
        scanf("%d %d", &retX, &retY);

        //fprintf(stderr, "retX %d retY %d, acc %d\n", retX, retY, acc);

        if (retX == 0 && retY == 0) {
            break;
        } else if (retX == -1 && retY == -1) {
            //printf("Error GG\n");
            exit(1);
        } else {
            m[retX][retY] = 1;
        }
        /*
        for (int iii = upperLeftX; iii < lowerRightX; iii++)
            for (int jjj = upperLeftY; jjj < lowerRightY; jjj++)
                fprintf(stderr, "%d%c", m[iii][jjj],
                        jjj == lowerRightY - 1 ? '\n' : ' ');
                */
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int ncase;
    scanf("%d", &ncase);
    for (int i = 1; i <= ncase; i++) {
        solve();
    }

    return 0;
}
