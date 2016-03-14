#include <bits/stdc++.h>
//LLONG_MIN LLONG_MAX INT_MIN INT_MAX

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    int ans = 0, cnt = 0;
    for(int i = 0; i < n; i++) {
	int tmp;
	scanf("%d", &tmp);
	if(tmp != -1)
	    cnt += tmp;
	else {
	    if(cnt > 0)
		cnt--;
	    else
		ans++;
	}
    }

    printf("%d\n", ans);
    
    return 0;
}
