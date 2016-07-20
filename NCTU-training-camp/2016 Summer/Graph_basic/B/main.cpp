#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    
    int inp[n], l[n];
    memset(l, 0, sizeof(l));
    for(int i = 0; i < n; i++) {
	scanf("%d", &inp[i]);
	inp[i] = inp[i] == -1 ? -1 : inp[i] - 1;
    }

    for(int i = 0; i < n; i++) {
	int cur = inp[i], cnt = 1;
	while(cur != -1) {
	    cnt++;
	    cur = inp[cur];
	}
	l[i] = cnt;
    }
    
    int ans = 0;
    for(int i = 0; i < n; i++)
	ans = max(ans, l[i]);
    printf("%d\n", ans);

    return 0;
}
