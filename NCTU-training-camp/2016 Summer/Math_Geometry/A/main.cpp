#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
int gcd(int x, int y)
{
    return x == 0 ? y : gcd(y % x, x);
}

int main()
{
    int n, x0, y0;
    scanf("%d %d %d", &n, &x0, &y0);
    
    map< ii, int > cnt;
    for(int i = 0; i < n; i++) {
	int x, y;
	scanf("%d %d", &x, &y);
	
	int dx = x - x0, dy = y - y0;
	if(dx == 0) {
	    cnt[ii(0, 1)]++;    
	} else if(dy == 0) {
	    cnt[ii(1, 0)]++;
	} else {
	    int g = gcd(dx, dy);
	    cnt[ii(dx / g, dy / g)]++;
	}
    }

    printf("%d\n", (int)cnt.size());

    return 0;
}
