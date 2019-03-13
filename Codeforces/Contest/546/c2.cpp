#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    // observation: NE - SW direction, all diagnals must retain the same number
    // set observation: we can get all desired diagnal permutations without
    // affecting other diagnals

    int n, m;
    scanf("%d %d", &n, &m);
    int orig[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &orig[i][j]);

    int res[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &res[i][j]);

    bool ok = true;
    for (int i = 0; i < n; i++) {
        vector<int> origSet, resSet;
        int x = i, y = 0;
        for (int j = 0; j < m; j++) {
            if (x < 0 || y >= m)
                break;

            origSet.push_back(orig[x][y]);
            resSet.push_back(res[x][y]);

            x--;
            y++;
        }

        sort(origSet.begin(), origSet.end());
        sort(resSet.begin(), resSet.end());
        if (origSet != resSet) {
            ok = false;
            break;
        }
    }

    for (int i = 1; i < m; i++) {
        vector<int> origSet, resSet;
        int x = n - 1, y = i;
        for (int j = 0; j < n; j++) {
            if (x < 0 || y >= m)
                break;

            origSet.push_back(orig[x][y]);
            resSet.push_back(res[x][y]);

            x--;
            y++;
        }

        sort(origSet.begin(), origSet.end());
        sort(resSet.begin(), resSet.end());
        if (origSet != resSet) {
            ok = false;
            break;
        }
    }

    if (ok == false)
        printf("NO\n");
    else
        printf("YES\n");

    return 0;
}
