#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);

    int inp[n];
    for(int i = 0; i < n; i++)
	scanf("%d", &inp[i]);
    
    int max_cnt = 0, ans = 0;
    for(int i = 0; i < 31; i++) {
	int tmp = -1, cnt = 0;
	for(int j = 0; j < n; j++) {
	    if( (inp[j] >> i) & 1) {
		tmp = tmp == -1 ? inp[j] : tmp & inp[j];
		cnt++;
	    }
	}

	if( (tmp & -tmp) != (1 << i) )
	    continue;
	else {
	    if(cnt > 0) {
		max_cnt = cnt;
		ans = i;
	    }
	}
    }
    
    if(max_cnt == 0)
	printf("-1\n");
    else {
	printf("%d\n", max_cnt);
	for(int i = 0; i < n; i++) {
	    if( ( inp[i] >> ans ) & 1 ) {
		printf("%d ", inp[i]);
	    }
	}
    }

    return 0;
}
