#include <bits/stdc++.h>
using namespace std;

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    long long int DP[n + 1];

    vector<int> inp[100010];
    for(int i = 0; i < m; i++) {
	int a, b;
	scanf("%d %d", &a, &b);
	inp[a].push_back(b);
	inp[b].push_back(a);
    }	    

    for(int i = 1; i <= n; i++)
	DP[i] = 1;
    
    long long int ans = 0;
    for(int i = 1; i <= n; i++) {
	for(int j = 0; j < (int)inp[i].size(); j++) {
	    if(inp[i][j] < i)
		continue;
	    DP[inp[i][j]] = max(DP[inp[i][j]], DP[i] + 1);
	    ans = max(ans, (long long)DP[inp[i][j]] * (long long)inp[inp[i][j]].size());
	    ans = max(ans, DP[i] *  (long long)inp[i].size());
	}
    }
    

    printf("%lld\n", ans);

    return 0;
}
