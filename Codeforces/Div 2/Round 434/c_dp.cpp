#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;

char inp[3333];

bool isVowel(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

ii dp[3002][3002];

vector<int> ansPos;

void getAns(int l, int r)
{
    if(r - l < 3)
        return;
    int pos = dp[l][r].second;
    if(pos != -1) {
        ansPos.push_back(pos);
        // printf("%d\n", pos);

        getAns(l, pos);
        getAns(pos, r);
    }
}
 
ii dfs(int l, int r) // [l, r)
{
    if(r - l < 3) {
        return ii(0, -1);
    }

    if(dp[l][r].first != -1) {
        return dp[l][r];
    }
    
    ii ans;
    ans.first = INT_MAX;
    int who = -1;
    for(int i = l; i + 2 < r; i++) {
        int cnt = 0;
        for(int j = i; j < r && j < i + 3; j++) {
            if(isVowel(inp[j]))
                break;
            cnt++;
        }
        
        if(cnt == 3 && (inp[i] != inp[i + 1] || inp[i + 1] != inp[i + 2])) {
            int res1 = dfs(l, i + 1).first + dfs(i + 1, r).first + 1;
            int res2 = dfs(l, i + 2).first + dfs(i + 2, r).first + 1;

            int res = min(res1, res2);
            if(res < ans.first) {
                ans.first = min(ans.first, res);
                who = res1 < res2 ? i + 1 : i + 2;
            }
        }
    }
    
    ans.first = (ans.first == INT_MAX ? 0 : ans.first);
    ans.second = who;
    // printf("%d %d %d %d\n", l, r, ans.first, ans.second);
    dp[l][r] = ans;
    return ans;
}

int main()
{
    scanf("%s", inp);
    memset(dp, -1, sizeof(dp));
    
    int len = strlen(inp);
    dfs(0, len);
    
    /*
    for(int i = 0; i <= len; i++)
        for(int j = 0; j <= len; j++)
            printf("(%3d, %3d)%c", dp[i][j].first, dp[i][j].second, j == len ? '\n' : ' ');
    printf("%d\n", dp[0][len].first);
    */
    getAns(0, len);
    
    sort(ansPos.begin(), ansPos.end());
    int idx = ansPos.size() == 0 ? -1 : 0;
    for(int i = 0; i < len; i++) {
        if(idx != -1 && ansPos[idx] == i) {
            printf(" ");
            idx++;
        }
        printf("%c", inp[i]);
    }
    printf("\n");

    return 0;
}
