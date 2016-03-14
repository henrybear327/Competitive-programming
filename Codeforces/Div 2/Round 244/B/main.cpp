#include <bits/stdc++.h>
//LLONG_MIN LLONG_MAX INT_MIN INT_MAX

using namespace std;

int main()
{
    int n, t, c;
    scanf("%d %d %d", &n, &t, &c);

    int inp[n];
    for(int i = 0; i < n; i++)
	scanf("%d", &inp[i]);

    int more = 0;
    for(int i = 0; i < c; i++) {
	if(inp[i] > t) 
	    more++;
    }

    int cnt = 0;
    for(int i = 0; i <= n - c; i++) {
	if(more == 0) {
	    cnt++;
	}     
	if(inp[i] > t)
	    more--;
	if(inp[i + c] > t)
	    more++;
    }


    printf("%d\n", cnt);

    return 0;
}
