#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

bool go(int x, int y, string &ans)
{
    if (x == 0 && y == 0) {
        return true;
    }
    if (x == 1 && y == 0) {
        ans += "E";
        return true;
    }
    if (x == 0 && y == 1) {
        ans += "N";
        return true;
    }
    if (x == -1 && y == 0) {
        ans += "W";
        return true;
    }
    if (x == 0 && y == -1) {
        ans += "S";
        return true;
    }

    if (abs(x) % 2 != abs(y) % 2) {
        if (abs(x) % 2 == 1) {
            if (go((x + 1) / 2, y / 2, ans)) {
                ans += "W";
                return true;
            }
            if (go((x - 1) / 2, y / 2, ans)) {
                ans += "E";
                return true;
            }
        } else {
            if (go(x / 2, (y + 1) / 2, ans)) {
                ans += "S";
                return true;
            }
            if (go(x / 2, (y - 1) / 2, ans)) {
                ans += "N";
                return true;
            }
        }
    }

    return false;
}

void solve()
{
    int x, y;
    scanf("%d %d", &x, &y);
    if (x == 0 && y == 0) {
        printf("\n");
        return;
    }

    string ans = "";
    if (go(x, y, ans) == false)
        printf("IMPOSSIBLE\n");
    else {
        reverse(ans.begin(), ans.end());
        printf("%s\n", ans.c_str());
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
