#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int BOUND = 1000;

void solve()
{
    int n;
    scanf("%d", &n);

    if (n == 1)
        printf("1\n");
    else if (n == 2)
        printf("1 2\n");
    else {
        /*
        int dp[BOUND] = {0};
        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 2;

        vector<int> ans;
        ans.push_back(1);
        ans.push_back(2);

        for(int i = 2; i < n; i++) {
                for(int j = 1; j < BOUND; j++) {
                        if(dp[j] != 0)
                                continue;
                        ans.push_back(j);

                        for(int k = BOUND - j; k >= 0; k--) {
                                if(dp[k] == 1 && dp[k + j] == 0)
                                        dp[k + j] = 2;
                        }

                        dp[j] = 1;
                        break;
                }
        }

        int sz = ans.size();
        for(int i = 0; i < sz; i++)
                // printf("%d%c", ans[i], i == sz - 1 ? '\n' : ' ');
                printf("%d%c", ans[i], " \n"[i==sz-1]);
        */

        for (int i = 1; i <= n; i++)
            printf("%d%c", 501 - i, " \n"[i == n]);
    }
}

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while (ncase--) {
        solve();
    }

    return 0;
}
