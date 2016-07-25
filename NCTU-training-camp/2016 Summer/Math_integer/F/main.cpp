#include <bits/stdc++.h>

using namespace std;

int main()
{
    int p, mn = INT_MAX;
    for(int i = 0; i < 4; i++) {
	scanf("%d", &p);
	mn = min(mn, p);
    }
    
    int a, b;
    scanf("%d %d", &a, &b);
    int ans = min(mn, b + 1) - a > 0 ? min(mn, b + 1) - a : 0;

    printf("%d\n", ans);
    /*
    int p[4], a, b;
    for(int i = 0; i < 4; i++)
	scanf("%d", &p[i]);
    scanf("%d %d", &a, &b);
	
    int ans = 0;
    for(int x = a; x <= b; x++) {
	sort(p, p + 4);
	
	int cnt = 0;
	do {
	    if(cnt >= 7) {
		ans++;
		break;
	    }
	    int tmp = (((x % p[0]) % p[1]) % p[2]) % p[3];
	    if(tmp == x)
		cnt++;
	} while(next_permutation(p, p + 4));
    }

    printf("%d\n", ans);
    */

    return 0;
}
