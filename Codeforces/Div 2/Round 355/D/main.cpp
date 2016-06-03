#include <bits/stdc++.h>
//LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

typedef long long int ll;

using namespace std;

typedef pair<int, int> ii;
#define x first
#define y second

int dist(ii a, ii b)
{
    return abs(a.x - b.x) + abs(a.y - b.y);
}

vector<ii> loc[90010];
int dp[333][333];
bool cmp(ii a, ii b)
{
    return dp[a.x][a.y] < dp[b.x][b.y];
}

int main()
{
    int n, m, p;
    scanf("%d %d %d", &n, &m, &p);
    
    int first;
    for(int i = 0; i < n; i++)
	for(int j = 0; j < m; j++) {
	    int tmp;
	    scanf("%d", &tmp);

	    if(i == 0 && j == 0)
		first = tmp;

	    loc[tmp].push_back(ii(i, j));
	}
    
    for(int i = 0; i < 333; i++)
	for(int j = 0; j < 333; j++)
	    dp[i][j] = INT_MAX;
    
    for(int i = 0; i < (int)loc[1].size(); i++) {
	int a = loc[1][i].x, b = loc[1][i].y;
	dp[a][b] = min(dp[a][b], dist(loc[first][0], loc[1][i]));
    }

    for(int i = 1; i < p; i++) {
	sort(loc[i].begin(), loc[i].end(), cmp);
	for(int j = 0; j < min((int)loc[i].size(), n + m); j++) {
	    int oa = loc[i][j].x, ob = loc[i][j].y;
	    for(int k = 0; k < (int)loc[i + 1].size(); k++) {
		int aa = loc[i + 1][k].x, bb = loc[i + 1][k].y;
		dp[aa][bb] = min(dp[aa][bb], dp[oa][ob] + dist(ii(oa, ob), ii(aa, bb)));

	    }
	}
    }
    
    int ans = INT_MAX;
    for(int i = 0; i < (int)loc[p].size(); i++)
	ans = min(ans, dp[loc[p][i].x][loc[p][i].y]);
    printf("%d\n", ans);
    
    return 0;
}
