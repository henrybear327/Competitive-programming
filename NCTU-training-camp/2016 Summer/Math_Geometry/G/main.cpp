#include <bits/stdc++.h>

using namespace std;

#define div2(x) ((x%2)==1?x/2+1:x/2)
int main()
{
    int a, x, y;
    scanf("%d %d %d", &a, &x, &y);
    
    int ans = -1;
    for(int i = 0; i < 1000010; i++) {
	if(i == y) {
	    if(i % a == 0)
		break;
	    int block = i / a;
	    if(block == 0) {
		if(-div2(a) < x && x < div2(a))
		    ans = 1;
		break;
	    } else {
		if(block % 2 == 1) {
		    // size 1
		    if(-div2(a) < x && x < div2(a))
			ans = 2 + 3 * (block / 2);
		    break;
		} else {
		    if(-a < x && x < 0)
			ans = 3 * (block / 2);
		    else if(0 < x && x < a)
			ans = 3 * (block / 2) + 1;
		    break;
		}
	    }
	}
    }

    printf("%d\n", ans);

    return 0;
}
