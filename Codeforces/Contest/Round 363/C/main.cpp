#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);
    
    pair<int, int> state[111];
    for(int i = 0; i < n; i++) {
	int cur;
	scanf("%d", &cur);
	
	state[i].second = cur & 1; //contest
	cur >>= 1;
	state[i].first = cur & 1; //gym
    }

    pair< ii, ii > dp[n];
    dp[0].first.first = state[0].first;
    dp[0].second.first = state[0].second;
    for(int i = 1; i < n; i++) {
	dp[i].first.first = max(dp[i - 1].first.second,
				max(dp[i - 1].second.first, dp[i - 1].second.second)) + state[i].first;
	dp[i].first.second = max(max(dp[i - 1].first.first, dp[i - 1].first.second), 
				 max(dp[i - 1].second.first, dp[i - 1].second.second));
	dp[i].second.first = max(max(dp[i - 1].first.first, dp[i - 1].first.second), 
				 dp[i - 1].second.second) + state[i].second;
	dp[i].second.second = max(max(dp[i - 1].first.first, dp[i - 1].first.second), 
				 max(dp[i - 1].second.first, dp[i - 1].second.second));
    }
    
    int ans = max(max(dp[n - 1].first.first, dp[n - 1].first.second),
	          max(dp[n - 1].second.first, dp[n - 1].second.second));
    printf("%d\n", abs(n - ans));
	
    return 0;
}
