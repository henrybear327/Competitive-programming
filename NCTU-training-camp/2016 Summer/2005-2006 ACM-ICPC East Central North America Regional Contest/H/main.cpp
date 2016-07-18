#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int inp[1010], dp[1010][1010], n;

int sol(int l, int r) // [l, r]
{
    if(dp[l][r] != -1)
	return dp[l][r];
    if(l == r)
	return dp[l][r] = inp[l];
    if(r - l == 1)
	return dp[l][r] = max(inp[l], inp[r]);
    
    //int ll = inp[l] + min(sol(l + 2, r), sol(l + 1, r - 1)); // l + 1, r
    //int rr = inp[r] + min(sol(l + 1, r - 1), sol(l, r - 2)); // l, r - 1

    int ll = inp[l];
    if(inp[l + 1] >= inp[r])
	ll += sol(l + 2, r);
    else
	ll += sol(l + 1, r - 1);

    int rr = inp[r];
    if(inp[l] >= inp[r - 1])
	rr += sol(l + 1, r - 1);
    else
	rr += sol(l, r - 2);

    return dp[l][r] = max(ll, rr);
}   

int main()
{
    int ncase = 1;
    while(scanf("%d", &n) == 1 && n) {
	memset(dp, -1, sizeof(dp));
	for(int i = 0; i < n; i++)
	    scanf("%d", &inp[i]);
	int sum = 0;
	for(int i = 0; i < n; i++)
	    sum += inp[i];
	
	int p1 = sol(0, n - 1);
	int p2 = sum - p1;
	printf("In game %d, the greedy strategy might lose by as many as %d points.\n", ncase++, abs(p1 - p2));
    }
	
    return 0;
}
