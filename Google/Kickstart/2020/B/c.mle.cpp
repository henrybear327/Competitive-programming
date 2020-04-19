#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

void solve()
{
    // 2(3(NW)2(W2(EE)W))
    // 3(S2(E))
    stack<int> numStack;
    stack<string> strStack;

    char inp[2222];
    scanf("%s", inp);

    string tmp = "";
    int n = strlen(inp);
    for (int i = 0; i < n; i++) {
        if ('0' <= inp[i] && inp[i] <= '9') {
            strStack.push(tmp);
            numStack.push(inp[i] - '0');
            tmp = "";

            i++; // skip (
        } else if (inp[i] == ')') {
            string op = "";
            int rep = numStack.top();
            numStack.pop();
            for (int j = 0; j < rep; j++) {
                op += tmp;
            }
            tmp = "";
            op = strStack.top() + op;
            strStack.pop();

            tmp = op;
        } else {
            tmp += inp[i];
        }
    }

    strStack.push(tmp);

    string ans;
    while (strStack.size() > 0) {
        ans = strStack.top() + ans;
        strStack.pop();
    }

    // printf("%s\n", ans.c_str());
    int x = 1;
    int y = 1;
    const char *dir = "NWES";
    const int dx[4] = {0, -1, 1, 0};
    const int dy[4] = {-1, 0, 0, 1};
    for (auto i : ans) {
        for (int j = 0; j < 4; j++) {
            if (dir[j] == i) {
                x = x + dx[j];
                y = y + dy[j];
                if (x < 1)
                    x = 1e9;
                else if (x == (int)1e9 + 1)
                    x = 1;

                if (y < 1)
                    y = 1e9;
                else if (y == (int)1e9 + 1)
                    y = 1;

                break;
            }
        }
    }
    printf("%d %d\n", x, y);
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
