#include <bits/stdc++.h>
//LLONG_MIN LLONG_MAX INT_MIN INT_MAX

using namespace std;

int n, k, d;
int ans = 0;
void dfs(int sum, bool satisfied)
{
    if(sum > n)
	return;
    if(sum == n) {
	if(satisfied)
	    ans++;
	return;
    }

    for(int i = 1; i <= k; i++) {
	dfs(sum + i, satisfied ? satisfied : (i >= d));
    }
}   

int main()
{
    scanf("%d %d %d", &n, &k, &d);

    dfs(0, false);

    printf("%d\n", ans);
    
    return 0;
}
