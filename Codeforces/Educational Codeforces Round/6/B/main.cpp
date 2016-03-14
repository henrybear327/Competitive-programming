#include <bits/stdc++.h>
//LLONG_MIN LLONG_MAX INT_MIN INT_MAX

using namespace std;

int num[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    
    int ans = 0;
    for(int i = a; i <= b; i++) {
	int tmp = i;
	while(tmp) {
	    int nummm = tmp % 10;
	    ans += num[nummm];
	    tmp /= 10;
	}
    }

    printf("%d\n", ans);

    return 0;
}
