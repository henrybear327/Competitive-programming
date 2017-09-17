#include <bits/stdc++.h>

using namespace std;

char inp[3333];
int dp[3333][3333];

bool isVowel(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int dfs(int l, int r) // [l, r)
{
    if(r - l < 3)
        return 0;
    if(dp[l][r] != -1)
        return dp[l][r];
    
    int ans = INT_MAX;
    int who = -1;
    for(int i = l; i + 2 < r; i++) {
        int cnt = 0;
        for(int j = i; j < r && j < i + 3; j++) {
            if(isVowel(inp[j]))
                break;
            cnt++;
        }
        
        if(cnt == 3 && (inp[i] != inp[i + 1] || inp[i + 1] != inp[i + 2])) {
            int res1 = dfs(l, i + 1) + dfs(i + 1, r) + 1;
            int res2 = dfs(l, i + 2) + dfs(i + 2, r) + 1;

            int res = min(res1, res2);
            if(res < ans) {
                ans = min(ans, res);
                who = res1 < res2 ? i + 1 : i + 2;
            }
        }
    }
    
    ans = ans == INT_MAX ? 0 : ans;
    printf("%d %d %d\n", l, r, ans);
    dp[l][r] = ans;
    return ans;
}

int main()
{
    scanf("%s", inp);
    memset(dp, -1, sizeof(dp));
    
    int len = strlen(inp);
    dfs(0, len);
    
    for(int i = 0; i <= len; i++)
        for(int j = 0; j <= len; j++)
            printf("%3d%c", dp[i][j], j == len ? '\n' : ' ');
    printf("%d\n", dp[0][len]);

    return 0;
}
