#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int cnt[21];

void solve(int n, int x)
{
    if (n == 1)
        printf("YES\n%d\n", x);
    else if (n == 2) {
        if (x == 0)
            printf("NO\n");
        else
            printf("YES\n0 %d\n", x);
    } else {
        memset(cnt, 0, sizeof(cnt));

        vector<int> ans;
        for (int i = 1; i < n; i++) {
            ans.push_back(i);

            int tmp = i;
            for (int j = 0; tmp > 0; j++) {
                if (tmp & 1)
                    cnt[j]++;
                tmp >>= 1;
            }
        }

        int adjustment = 0;
        for (int i = 0; i <= 20; i++) {
            bool isOdd = ((x >> i) & 1);
            if ((cnt[i] & 1) != isOdd)
                adjustment += ((1 << i));
        }

        bool ok = true;
        bool needAdjustment = false;
        for (int i = 0; i < (int)ans.size(); i++) {
            if (ans[i] > 1000000)
                ok = false;
            if (adjustment == ans[i]) {
                needAdjustment = true;
                // ans[i] += (1 << 18); // error
            }
        }

        if (needAdjustment) {
            for (int i = 0; i < (int)ans.size(); i++) {
                if (ans[i] != adjustment) {
                    ans[i] += (1 << 19);
                    needAdjustment = false;
                    break;
                }
            }

            if (needAdjustment)
                ok = false;
            adjustment += (1 << 19);
        }
        ans.push_back(adjustment);

        printf("%s\n", ok ? "YES" : "NO");
        if (ok) {
            int check = 0;
            for (int i = 0; i < (int)ans.size(); i++) {
                check ^= ans[i];
                printf("%d%c", ans[i], i == (int)ans.size() - 1 ? '\n' : ' ');
            }
        }
    }
}

int main()
{
    int n, x;
    scanf("%d %d", &n, &x);
    solve(n, x);

    return 0;
}
