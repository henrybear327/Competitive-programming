#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int ncase, f;
void solve()
{
    char ans[120 * 5] = {'\0'};
    set<string> has;
    int remaining = f;
    for (int i = 0; i < 119 * 5; i++) {
        if (remaining == 0)
            break;
        if (i % 5 == 4) {
            // get string
            int cnt[5] = {0};
            for (int j = 1; j <= 4; j++)
                cnt[ans[i - j] - 'A']++;

            for (int j = 0; j < 5; j++)
                if (cnt[j] == 0)
                    ans[i] = j + 'A';

            string tmp;
            tmp += ans[i - 4];
            tmp += ans[i - 3];
            tmp += ans[i - 2];
            tmp += ans[i - 1];
            tmp += ans[i];
            has.insert(tmp);

            // fprintf(stderr, "%s\n", tmp.c_str());

            continue;
        }

        printf("%d\n", i + 1);
        // fprintf(stderr, "%d\n", i + 1);
        fflush(stdout);
        remaining--;
        char c[100];
        scanf("%s", c);

        ans[i] = c[0];
    }

    // get ans string first 3
    // fprintf(stderr, "%d %d\n", remaining, (int)has.size());
    assert(has.size() == 118);

    int cnt[3][5];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < 119 * 5; i++) {
        if (i % 5 <= 2) {
            cnt[i % 5][ans[i] - 'A']++;
        }
    }

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 5; j++) {
            // fprintf(stderr, "%d %d %d\n", i, j, cnt[i][j]);
            if (cnt[i][j] != 24)
                ans[120 * 5 - (5 - i)] = j + 'A';
        }

    // debug
    /*for (int i = 120 * 5 - 5; i < 120 * 5; i++)
        printf("%c", ans[i]);
    printf("\n");
        */

    // enumerate
    for (int i = 0; i < 5; i++) {
        if (ans[120 * 5 - 5] - 'A' == i || ans[120 * 5 - 4] - 'A' == i ||
            ans[120 * 5 - 3] - 'A' == i)
            continue;
        for (int j = 0; j < 5; j++) {
            if (i == j)
                continue;
            if (ans[120 * 5 - 5] - 'A' == j || ans[120 * 5 - 4] - 'A' == j ||
                ans[120 * 5 - 3] - 'A' == j)
                continue;

            for (int x = 0; x < 5; x++) {
                if (ans[119 * 5 - 5] - 'A' == x || ans[119 * 5 - 4] - 'A' == x ||
                    ans[119 * 5 - 3] - 'A' == x)
                    continue;
                for (int y = 0; y < 5; y++) {
                    if (x == y)
                        continue;
                    if (ans[119 * 5 - 5] - 'A' == y || ans[119 * 5 - 4] - 'A' == y ||
                        ans[119 * 5 - 3] - 'A' == y)
                        continue;

                    string ansStr = string(ans + 119 * 5, ans + 120 * 5);
                    ansStr[3] = i + 'A';
                    ansStr[4] = j + 'A';
                    string candStr = string(ans + 118 * 5, ans + 119 * 5);
                    candStr[3] = x + 'A';
                    candStr[4] = j + 'A';

                    // fprintf(stderr, "%s %s\n", ansStr.c_str(), ansStr.c_str());
                    if (has.find(ansStr) == has.end() && has.find(candStr) == has.end()) {
                        printf("%s\n", ansStr.c_str());
                        fflush(stdout);

                        char ccc[100];
                        scanf("%s", ccc);
                        if (ccc[0] == 'Y')
                            return;
                        else
                            assert(1 != -1);
                    }
                }
            }
        }
    }
}

int main()
{
    scanf("%d %d", &ncase, &f);
    for (int i = 1; i <= ncase; i++) {
        solve();
    }
}
