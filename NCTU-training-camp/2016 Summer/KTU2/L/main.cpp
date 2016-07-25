#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

#define N 1010
ll inp[N][N], dp[N][N], dp1[N][N];

int n;
ll w;
bool bound(int x, int y)
{
    return (1 <= x && x <= n) && (1 <= y && y <= n);
}

#define DEBUG 0

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while(ncase--) {
        // read n
        scanf("%d %lld", &n, &w);

        // init
        memset(dp, 0, sizeof(dp));
        memset(dp1, 0, sizeof(dp1));
        memset(inp, 0, sizeof(inp));

        // read matrix
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                scanf("%lld", &inp[i][j]);

#if DEBUG == 1
        for(int i = 0; i <= n + 1; i++)
            for(int j = 0; j <= n + 1; j++) {
                printf("%lld%c", inp[i][j], j == n + 1 ? '\n' : ' ');
            }
        printf("\n");
#endif

        /*  compute prefix sum
            ..*
            .*.
            *..
        */
        // row
        for(int i = 1; i < n; i++) {
            int x = 1, y = i;
            while(bound(x, y)) {
                dp[x][y] = inp[x][y] + dp[x - 1][y + 1];
                x++;
                y--;
            }
        }
        //column
        for(int j = 1; j <= n; j++) {
            int x = j, y = n;
            while(bound(x, y)) {
                dp[x][y] = inp[x][y] + dp[x - 1][y + 1];
                x++;
                y--;
            }
        }

#if DEBUG == 1
        for(int i = 0; i <= n + 1; i++)
            for(int j = 0; j <= n + 1; j++) {
                printf("%lld%c", dp[i][j], j == n + 1 ? '\n' : ' ');
            }
        printf("\n");
#endif

        /*  compute prefix sum
            *..
            .*.
            ..*
        */

        // row
        for(int i = 2; i <= n; i++) {
            int x = 1, y = i;
            while(bound(x, y)) {
                dp1[x][y] = inp[x][y] + dp1[x - 1][y - 1];
                x++;
                y++;
            }
        }
        //column
        for(int j = 1; j <= n; j++) {
            int x = j, y = 1;
            while(bound(x, y)) {
                dp1[x][y] = inp[x][y] + dp1[x - 1][y - 1];
                x++;
                y++;
            }
        }

#if DEBUG == 1
        for(int i = 0; i <= n + 1; i++)
            for(int j = 0; j <= n + 1; j++) {
                printf("%lld%c", dp1[i][j], j == n + 1 ? '\n' : ' ');
            }
        printf("\n");
#endif

        // binary search for size which is <= W
        // TTTTFFFFF
        int l = 0, r = n + 1;
        while(r - l > 1) {
            int mid = (l + r) / 2;

            bool ok = false;
            for(int i = 1; i <= n && ok == false; i++) {
                for(int j = 1; j <= n; j++) {
                    if(max(i + mid - 1, j + mid - 1) > n)
                        continue;

                    ll sum1 = dp[i + mid - 1][j] - dp[i - 1][j + mid];
                    ll sum2 = dp1[i + mid - 1][j + mid - 1] - dp1[i - 1][j - 1];
                    ll sum = sum1 + sum2;
                    if(mid % 2 == 1) {
                        // minus center
                        sum -= inp[i + mid / 2][j + mid / 2];
                    }
                    if(sum <= w) {
                        ok = true;
                        break;
                    } else {
                        continue;
                    }
                }
            }

            if(ok == true)
                l = mid;
            else
                r = mid;
        }

        // output max_size
        printf("%d\n", l);
    }

    return 0;
}