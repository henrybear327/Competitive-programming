#include <bits/stdc++.h>

using namespace std;

int main()
{   
    int pl[1000]; //prime list
    bool isp[1010];
    for(int i = 0; i < 1010; i++)
	isp[i] = true;

    for(int i = 2; i < 1010; i++) {
	if(isp[i] == true) {
	    for(int j = 2; i * j < 1010; j++) {
		isp[i * j] = false;
	    }
	}
    }

    int idx = 0;
    for(int i = 1; i < 1010; i++)
	if(isp[i] == true)
	    pl[idx++] = i;
    
    int n, c;
    while(scanf("%d %d", &n, &c) == 2) {
	printf("%d %d:", n, c);
	
	int cnt = 0;
	while(pl[cnt] <= n)
	    cnt++;
	
	c = cnt % 2 == 1 ? c * 2 - 1 : c * 2;

	int start = (cnt - c) / 2;
	if(c >= cnt) {
	    start = 0;
	    c = cnt;
	}
	for(int i = 0; i < c; i++)
	    printf(" %d", pl[start + i]);
	printf("\n\n");
    }

    return 0;
}
