#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

void solve()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int rem = n * n - 1 - k;

    bool ok = rem % 2 == 0;

    if (ok) {
        vector<ii> ans;

        // 4 per group
        // only care about the "save"
        int base = 1;
        int next_base = 1 + (n - 1) * 4;
        for (int i = n; i >= 3 && rem > 0; i -= 2) {
            int starting = (i / 2) * 4 * 2 - 2;
            // printf("rem %d starting %d\n", rem, starting);
            for (int j = 0; j <= 6; j += 2) {
                if (rem - (starting - j) >= 0) {
                    // printf("deduct %d\n", starting - j);
                    int offset = 0;
                    if (j >= 1) {
                        offset = i * (j / 2) - (j / 2 - 1);
                    }
                    // printf("offset %d\n", offset);
                    ans.push_back({base + offset, base + offset + (starting - j) + 1});

                    rem -= starting - j;

                    break;
                }
            }
            base = next_base;
            next_base = next_base + (i - 2 - 1) * 4;

            // printf("%d %d\n", base, next_base);
        }

        if (rem == 0) {
            printf("%d\n", (int)ans.size());
            for (auto tmp : ans) {
                printf("%d %d\n", tmp.first, tmp.second);
            }

            return;
        }
    }

    printf("IMPOSSIBLE\n");
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
