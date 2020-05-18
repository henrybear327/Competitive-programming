#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

void solve()
{
    int n, m;
    scanf("%d %d", &n, &m);

    char inp[30][33];
    bool has[26] = {false};
    for (int i = 0; i < n; i++) {
        scanf("%s", inp[i]);
        for (int j = 0; j < m; j++)
            has[inp[i][j] - 'A'] = true;
    }

    int tot = 0;
    for (int i = 0; i < 26; i++)
        if (has[i])
            tot++;

    bool used[26] = {false};
    auto check = [&](int who) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (inp[i][j] == who + 'A') {
                    if (i == n - 1)
                        continue;
                    if (inp[i][j] == inp[i + 1][j])
                        continue;
                    if (used[inp[i + 1][j] - 'A'])
                        continue;
                    return false;
                }
            }
        }

        return true;
    };

    string ans;
    bool ok = true;
    do {
#if DEBUG
        printf("before\n");
        for (int i = 0; i < 26; i++)
            if (has[i])
                printf("%c %d\n", i + 'A', used[i]);
#endif

        ok = true;
        bool hasMove = false;
        int cnt = 0;
        for (int i = 0; i < 26; i++) {
            if (has[i] && used[i] == false) {
                ok = false;

                if (check(i)) {
                    char c = i + 'A';
                    used[i] = true, ans += c;
                    hasMove = true;
                }
            }

            if (has[i] && used[i])
                cnt++;
        }

        if (cnt == tot)
            break;

#if DEBUG
        printf("after\n");
        for (int i = 0; i < 26; i++)
            if (has[i])
                printf("%c %d\n", i + 'A', used[i]);
#endif
        if (hasMove == false) {
            ans = "-1";
            break;
        }
    } while (ok == false);

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

    return 0;
}
