#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while(scanf("%d", &n) == 1 && n) {
	int inp[n];
	for(int i = 0; i < n; i++)
	    scanf("%d", &inp[i]);
	
	sort(inp, inp + n);
    
	int ans = INT_MAX;
	for(int i = 1; i < n; i++)
	    ans = min(ans ,inp[i] - inp[i - 1]);
	printf("%d\n", ans);
    }

    return 0;
}
