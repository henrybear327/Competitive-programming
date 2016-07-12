#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    
    int mn = INT_MAX;
    int inp[n];
    for(int i = 0; i < n; i++) {
	scanf("%d", &inp[i]);
	mn = min(mn, inp[i]);
    }	    
    
    bool ok = true;
    for(int i = 0; i < n; i++)
	if(inp[i] % mn != 0) {
	    ok = false;
	    break;
	}

    if(ok)
	printf("%d\n", mn);
    else
	printf("-1\n");

    return 0;
}
