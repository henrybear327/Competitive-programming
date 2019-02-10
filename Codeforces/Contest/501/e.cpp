#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

struct Data {
    int s, t, r;
};

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    char inp[n][m + 3];
    for (int i = 0; i < n; i++)
        scanf("%s", inp[i]);

    // get max length of up, down, left, right of all (x, y)
    int up[n][m], down[n][m], left[n][m], right[n][m];
    memset(up, 0, sizeof(up));
    memset(down, 0, sizeof(down));
    memset(left, 0, sizeof(left));
    memset(right, 0, sizeof(right));

    /*
    5 10
    .*...*..*.
    ***..*.***
    .*.******.
    ***..*....
    .*...*....
    */

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (inp[i][j] == '*') {
                // you can't simply put a >0 number at a . location...
                if (j + 1 < m && inp[i][j + 1] == '*')
                    left[i][j + 1] = left[i][j] + 1;
                if (i + 1 < n && inp[i + 1][j] == '*')
                    up[i + 1][j] = up[i][j] + 1;
            }
        }

    for (int i = n - 1; i >= 0; i--)
        for (int j = m - 1; j >= 0; j--) {
            if (inp[i][j] == '*') {
                if (j - 1 >= 0 && inp[i][j - 1] == '*')
                    right[i][j - 1] = right[i][j] + 1;
                if (i - 1 >= 0 && inp[i - 1][j] == '*')
                    down[i - 1][j] = down[i][j] + 1;
            }
        }

    // for every point, mark the left-right and up-down bound
    int hStart[n][m], hEnd[n][m];
    int vStart[n][m], vEnd[n][m];
    memset(hStart, 0, sizeof(hStart));
    memset(vStart, 0, sizeof(vStart));
    memset(hEnd, 0, sizeof(hEnd));
    memset(vEnd, 0, sizeof(vEnd));
    vector<Data> ans;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int mn = min(min(left[i][j], right[i][j]), min(up[i][j], down[i][j]));
            // printf("%d", mn);

            if (mn > 0) {
                hStart[i][j - mn]++;
                hEnd[i][j + mn]++;
                vStart[i - mn][j]++;
                vEnd[i + mn][j]++;

                ans.push_back({i, j, mn});
            }
        }
        // printf("\n");
    }

    // check
    char draw[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            draw[i][j] = '.';
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < m; j++) {
            sum += hStart[i][j];

            if (sum > 0)
                draw[i][j] = '*';

            sum -= hEnd[i][j];
        }
    }

    for (int j = 0; j < m; j++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += vStart[i][j];

            if (sum > 0)
                draw[i][j] = '*';

            sum -= vEnd[i][j];
        }
    }

    bool error = false;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (inp[i][j] != draw[i][j]) {
                // printf("%d %d\n", i, j);
                error = true;
            }

    if (error)
        printf("-1\n");
    else {
        printf("%d\n", (int)ans.size());
        for (auto i : ans)
            printf("%d %d %d\n", i.s + 1, i.t + 1, i.r);
    }

    return 0;
}
