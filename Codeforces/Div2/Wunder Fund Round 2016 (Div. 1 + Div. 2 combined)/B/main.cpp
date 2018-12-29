#include <bits/stdc++.h>
//LLONG_MIN LLONG_MAX INT_MIN INT_MAX

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    
    int ans[51] = {0}, used[51] = {0};
    for(int i = 0; i < n; i++) {
	int mx = INT_MIN;
	for(int j = 0; j < n; j++) {
	    int tmp;
	    scanf("%d", &tmp);
	    mx = max(mx, tmp);
	}
	if(used[mx] == 0){
	    ans[i] = mx;
	    used[mx] = 1;
	} else {
	    ans[i] = mx + 1;
	    used[mx + 1] = 1;
	}
    }

    for(int i = 0; i < n; i++)
	printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');

    return 0;
}
