#include <bits/stdc++.h>

using namespace std;

int g[111][111];
int cal(int lx, int ly, int rx, int ry)
{
    int cnt = 0;
    for (int i = lx; i < rx; i++)
        for (int j = ly; j < ry; j++)
            if (g[i][j] == 1)
                cnt++;
    return cnt;
}

bool solve()
{
    int r, c, h, v;
    scanf("%d %d %d %d", &r, &c, &h, &v);

    char inp[c + 10];
    int total = 0;
    for (int i = 0; i < r; i++) {
        scanf("%s", inp);

        for (int j = 0; j < c; j++) {
            g[i][j] = (inp[j] == '@' ? 1 : 0);
            if (inp[j] == '@')
                total++;
        }
    }

    int perArea = 0;
    if (total % ((h + 1) * (v + 1)) == 0) {
        perArea = total / ((h + 1) * (v + 1));
    } else
        return false;
    if (total == 0)
        return true;

    // vetical cut
    vector<int> vCut;
    vCut.push_back(0);
    for (int i = 1; i <= c; i++) { // cut on left edge
        int left = vCut.back();
        int right = i;
        int cnt = 0;
        for (int j = left; j < right; j++) {
            for (int k = 0; k < r; k++) {
                if (g[k][j] == 1)
                    cnt++;
            }
        }

        if (cnt == perArea * (h + 1))
            vCut.push_back(i);
    }

    if ((int)vCut.size() != v + 2)
        return false;

    // horizontal cut
    vector<int> hCut;
    hCut.push_back(0);
    for (int i = 1; i <= r; i++) { // cut on upper edge
        int upper = hCut.back();
        int lower = i;
        bool ok = true;
        for (int j = upper; ok && j < lower; j++) {
            for (int k = 1; k < (int)vCut.size(); k++) {
                if (cal(upper, vCut[k - 1], lower, vCut[k]) != perArea) {
                    ok = false;
                    break;
                }
            }
        }
        if (ok == true)
            hCut.push_back(i);
    }
    if ((int)hCut.size() != h + 2)
        return false;

    return true;
}

int main()
{
    int ncase;
    scanf("%d", &ncase);
    for (int i = 1; i <= ncase; i++) {
        printf("Case #%d: %s\n", i, solve() ? "POSSIBLE" : "IMPOSSIBLE");
    }
    return 0;
}
