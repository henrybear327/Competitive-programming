#include <bits/stdc++.h>
//LLONG_MIN LLONG_MAX INT_MIN INT_MAX

using namespace std;

int limit[50], ans[50];
int used[51];
int n;
bool ok;
void dfs(int curr)
{
    if(curr == n && ok == false) {
	for(int i = 0; i < n; i++)
	    printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');
	ok = true;
	return;
    }

    for(int i = limit[curr]; i <= n && ok == false; i++) {
	if(used[i] == 0) {
	    used[i] = 1;
	    ans[curr] = i;

	    dfs(curr + 1);

	    used[i] = 0;
	    ans[curr] = 0;
	}
    }
}

int main()
{
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
	int mx = INT_MIN;
	for(int j = 0; j < n; j++) {
	    int tmp;
	    scanf("%d", &tmp);
	    mx = max(mx, tmp);
	}
	limit[i] = mx;
    }
    
    memset(used, 0, sizeof(used));
    ok = false;
    dfs(0);

    return 0;
}
