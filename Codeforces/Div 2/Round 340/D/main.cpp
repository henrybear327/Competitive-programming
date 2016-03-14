#include <bits/stdc++.h>
// solution 2: ans == 2 when all dots are on the corners of a rectangle!

using namespace std;

int main()
{
    pair<int, int> inp[3];
    for(int i = 0; i < 3; i++)
	scanf("%d %d", &inp[i].first, &inp[i].second);
    
    sort(inp, inp + 3);
	
    int a = inp[0].first;
    int b = inp[1].first;
    int c = inp[2].first;
    int d = inp[0].second;
    int e = inp[1].second;
    int f = inp[2].second;

    int ans = -1;
    // on same x/y axis
    if(a == b && b == c)
	ans = 1;
    if(d == e && e == f)
	ans = 1;
    
    // two dots in a line
    if(ans == -1) {
	if(a == b) {
	    if(d < f && f < e)
		ans = 3;
	    else
		ans = 2;
	} else if(b == c) {
	    if(e < d && d < f)
		ans = 3;
	    else
		ans = 2;
	} else if(d == e) {
	    if(a < c && c < b)
		ans = 3;
	    else
		ans = 2;
	} else if(e == f) {
	    if(b < a && a < c)
		ans = 3;
	    else
		ans = 2;
	} else {
	    // else
	    ans = 3;
	}
    }
    
    printf("%d\n", ans);

    return 0;
}
