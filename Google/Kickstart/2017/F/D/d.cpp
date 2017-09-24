#include <bits/stdc++.h>

using namespace std;

int dp[10001];
void build()
{
    vector<int> avail;
    for(int i = 1; i * i <= 10000; i++)
        avail.push_back(i * i);
    
    fill(dp, dp + 10000 + 1, INT_MAX);
    dp[0] = 0;
    
    for(int j = 0; j < (int)avail.size(); j++) {
        int val = avail[j];
        
        for(int i = 0; i <= 10000; i++) {
            if(i + val > 10000)
                break;
            
            dp[i + val] = min(dp[i] + 1, dp[i +val]);
        }
    }
}

void solve(int ncase)
{
    int n;
    scanf("%d", &n);

    printf("Case #%d: %d\n", ncase, dp[n]);
}

int main()
{
    build();
    
    int ncase;
    scanf("%d", &ncase);
    
    for(int i = 0; i < ncase; i++) {
        solve(i + 1);
    }
    
    return 0;
}