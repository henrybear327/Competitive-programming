// observations
// 1. swap operation won't change the number of X in row/col
// 2. must have, and only have, a row/col with only 1 X in it

#include <bits/stdc++.h>

using namespace std;

string solve()
{
    int n;
    scanf("%d", &n);

    // read
    char inp[n][n + 1];
    for (int i = 0; i < n; i++)
        scanf("%s", inp[i]);

    // find bounding box
    // check box: have (n - 1) / 2
    int boxCnt = 0;
    bool used[n];
    memset(used, false, sizeof(used));
    for (int i = 0; i < n; i++) {
        if (used[i])
            continue;

        int sameRowCnt = 0, j_backup = -1;
        for (int j = 0; j < n; j++) {
            if (i == j)
                continue;
            if (used[j])
                continue;

            bool diff = false;
            for (int k = 0; k < n; k++) {
                if (inp[i][k] == inp[j][k])
                    continue;
                else {
                    diff = true;
                    break;
                }
            }

            if (diff == false) {
                sameRowCnt++;
                j_backup = j;
            }
        }

        if (sameRowCnt == 1) {
            used[i] = used[j_backup] = true;
            boxCnt++;
        }
    }

    if (boxCnt == (n - 1) / 2) {
        // one X row/col, see testcase my.in
        int x = -1;
        for (int i = 0; i < n; i++)
            if (used[i] == false) {
                x = i;
                break;
            }

        int y = -1;
        for (int i = 0; i < n; i++) {
            if (inp[x][i] == 'X') {
                y = i;
                break;
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (inp[i][y] == 'X')
                cnt++;
        }

        if (cnt == 1)
            return "POSSIBLE";
        return "IMPOSSIBLE";
    }
    return "IMPOSSIBLE";
}

int main()
{
    int ncase;
    scanf("%d", &ncase);
    for (int i = 1; i <= ncase; i++) {
        printf("Case #%d: %s\n", i, solve().c_str());
    }
}
