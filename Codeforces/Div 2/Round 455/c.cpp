#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

const int MOD = 1e9 + 7;

int main()
{
    int n;
    scanf("%d", &n);

    char inp[111];
    scanf("%s", inp);
    char prev, cur;
    ll dp[2][11111];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    prev = inp[0];
    for(int i = 1; i < n; i++) {
        scanf("%s", inp);
        cur = inp[0];
        int which = i % 2;
        
        memset(dp[which], 0, sizeof(dp[which])); 
        if(prev == 'f') {
            for(int j = 1; j < 11111; j++) {
                dp[which][j] = dp[which ^ 1][j - 1];
            }
        } else {
            ll sum = 0;
            for(int j = 0; j < 11111; j++) 
                sum = (sum + dp[which ^ 1][j]) % MOD;

            for(int j = 0; j < 11111; j++) {
                dp[which][j] = sum;
                sum -= dp[which ^ 1][j];
                if(sum < 0)
                    sum += MOD;
            }
        }
        
        /*
        for(int j = 0; j < 10; j++)
            printf("%lld ", dp[which][j]);
        puts("");
        */

        prev = cur;
    }


    ll sum = 0;
    for(int j = 0; j < 11111; j++) 
        sum = (sum + dp[(n - 1) % 2][j]) % MOD;
    printf("%lld\n", sum);

    return 0;
}
