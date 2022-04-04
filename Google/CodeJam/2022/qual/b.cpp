#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int data[3][4];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &data[i][j]);
        }
    }

    // find min ink level of 4 colors between 3 printers
    int sum = 0;
    vector<int> ans;
    for (int i = 0; i < 4; i++) {
        int mn = 1e9;
        for (int j = 0; j < 3; j++) {
            mn = min(mn, data[j][i]);
        }
        sum += mn;
        ans.push_back(mn);
    }

    if (sum >= 1000000) {
        // post processing
        sum = 0;
        for (int i = 0; i < ans.size(); i++) {
            if (sum == 1000000) {
                ans[i] = 0;
            } else {
                if (sum + ans[i] <= 1000000) {
                    sum += ans[i];
                } else {
                    ans[i] = 1000000 - sum;
                    sum = 1000000;
                }
            }
        }

        // print
        for (int i = 0; i < ans.size(); i++) {
            printf("%d%c", ans[i], i == ans.size() - 1 ? '\n' : ' ');
        }
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
