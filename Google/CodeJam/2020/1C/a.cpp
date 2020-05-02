#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

void solve()
{
    int x, y;
    scanf("%d %d", &x, &y);

    char inp[1111];
    scanf("%s", inp);

    int len = strlen(inp);
    const int dx[4] = {0, 0, 1, -1};
    const int dy[4] = {1, -1, 0, 0};
    const char *dir = "NSEW";
    int mn = INT_MAX;
    for (int i = 0; i < len; i++) {
        // cal
        int dist = abs(x) + abs(y);
        //   printf("%d, %d %d, %d\n", i, x, y, dist);
        if (dist <= i)
            mn = min(mn, i);

        // update
        for (int j = 0; j < 4; j++) {
            if (dir[j] == inp[i]) {
                x += dx[j];
                y += dy[j];
                break;
            }
        }
    }
    int dist = abs(x) + abs(y);
    if (dist <= len)
        mn = min(mn, len);

    if (mn == INT_MAX)
        printf("IMPOSSIBLE\n");
    else
        printf("%d\n", mn);
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
