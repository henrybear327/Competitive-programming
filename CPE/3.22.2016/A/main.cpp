#include <bits/stdc++.h>

using namespace std;

int main()
{
    int ncase;
    scanf("%d", &ncase);
    int cnt = 1;
    while(ncase--) {
	int n;
	scanf("%d", &n);

	int inp[n];
	for(int i = 0; i < n; i++)
	    scanf("%d", &inp[i]);

	int h = 0, l = 0;
	for(int i = 1; i < n; i++) {
	    if(inp[i] > inp[i - 1])
		h++;
	    else if(inp[i] < inp[i - 1])
		l++;
	}

	printf("Case %d: %d %d\n", cnt++, h, l);
    }

    return 0;
}
