#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const char *dir = "ESWN";
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};

int x, y;
string ans = "AAAAAAAAAAAAAAAAAAAAAAAAAAA";
string path = "";
void dfs(int depth, ll val, int curX, int curY)
{
    // printf("%s\n", path.c_str());
    // printf("%s\n", path.c_str());
    if (depth == 10) {
        return;
    }

    if (x == curX && y == curY) {
        // printf("ans = %s\n, path = %s\n", ans.c_str(), path.c_str());
        if (ans.length() > path.length()) {
            ans = path;
            return;
        }
    }

    // to A
    for (int i = 0; i < 4; i++) {
        path += dir[i];
        dfs(depth + 1, val * 2, curX + dx[i] * val, curY + dy[i] * val);
        path.pop_back();
    }
}

void solve()
{
    scanf("%d %d", &x, &y);
    if (x == 0 && y == 0) {
        printf("\n");
        return;
    }

    ans = "AAAAAAAAAA";
    path = "";
    dfs(0, 1, 0, 0);

    if (ans.length() != 10) {
        printf("%s\n", ans.c_str());
    } else {
        printf("IMPOSSIBLE\n");
    }
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
