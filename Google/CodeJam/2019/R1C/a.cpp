#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

char inp[260][555];
void solve()
{
    int n;
    scanf("%d", &n);
    memset(inp, '\0', sizeof(inp));

    int l[260];
    for (int i = 0; i < n; i++) {
        scanf("%s", inp[i]);
        l[i] = strlen(inp[i]);
    }

    bool used[260] = {false};
    int idx[260] = {0};
    string ans;
    for (;;) {
        // count type
        int cnt[3] = {0};
        for (int j = 0; j < n; j++) {
            if (used[j] == false) {
                char c = inp[j][idx[j]];
                if (c == 'R')
                    cnt[0]++;
                else if (c == 'P')
                    cnt[1]++;
                else
                    cnt[2]++;
            }
        }

        int zero = 0;
        for (int j = 0; j < 3; j++)
            if (cnt[j] == 0)
                zero++;

        // determine the move
        if (zero == 0) {
            printf("IMPOSSIBLE\n");
            return;
        } else if (zero == 1) {
            for (int j = 0; j < 3; j++) {
                if (cnt[j] == 0) {
                    if (j == 0)
                        ans += "S";
                    else if (j == 1)
                        ans += "R";
                    else
                        ans += "P";
                }
            }
        } else if (zero == 2) {
            for (int j = 0; j < 3; j++) {
                if (cnt[j] != 0) {
                    if (j == 0)
                        ans += "P";
                    else if (j == 1)
                        ans += "S";
                    else
                        ans += "R";
                }
            }
        } else {
            // impossible
        }

        // eliminate
        for (int j = 0; j < n; j++) {
            if (used[j] == false) {
                char c = inp[j][idx[j]];
                if (ans.back() == 'P' && c == 'R')
                    used[j] = true;
                else if (ans.back() == 'R' && c == 'S')
                    used[j] = true;
                else if (ans.back() == 'S' && c == 'P')
                    used[j] = true;

                idx[j]++;
                idx[j] %= l[j];
            }
        }

        bool ok = false;
        for (int j = 0; j < n; j++)
            if (used[j] == false)
                ok = true;
        if (ok == false)
            break;
    }

    printf("%s\n", ans.c_str());
}

int main()
{
    int ncase;
    scanf("%d", &ncase);
    for (int i = 1; i <= ncase; i++) {
        printf("Case #%d: ", i);
        solve();
    }
}
