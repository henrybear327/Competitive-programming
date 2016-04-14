#include <bits/stdc++.h>

using namespace std;

int inp[10010], k;
int bsearch(int l, int r, int t)
{ 
    // [l, r)
    while(l < r) {
	int mid = (l + r) / 2;
	if(inp[mid] == t)
	    return mid;
	else if(inp[mid] < t) 
	    l = mid + 1;
	else
	    r = mid;
    }
    return -1;
}

int main()
{
    int n;
    while(scanf("%d", &n) == 1) {
	for(int i = 0; i < n; i++)
	    scanf("%d", &inp[i]);
	scanf("%d", &k);

	sort(inp, inp + n);
	int ansa = INT_MAX, ansb = 0;
	for(int i = 0; i < n; i++) {
	    int idx;
	    if((idx = bsearch(i + 1, n, k - inp[i])) != -1) {
		if(abs(ansa - ansb) > abs(inp[i] - inp[idx])) {
		    ansa = inp[i];
		    ansb = inp[idx];
		}
	    }
	}

	printf("Peter should buy books whose prices are %d and %d.\n\n", min(ansa, ansb), max(ansa, ansb));
    }

    return 0;
}
