#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-9
int main()
{
    int n, R, r;
    scanf("%d %d %d", &n, &R, &r);
    
    if(r > R) {
	printf("NO\n");
	return 0;
    } else if(r == R) {
	printf("%s\n", n <= 1 ? "YES" : "NO"); 
	return 0;
    } else if(r * 2 >= R) {
	if( (r * 2 > R && n > 1) || (r * 2 == R && n > 2) )
	    printf("NO\n");
	else
	    printf("YES\n");
	    
	return 0;
    }

    double angle = 2 * asin((double)r / (double)(R - r));
    double ans = 2 * acos(-1) / angle;
    
    if(ans + EPS >= n)
	printf("YES\n");
    else
	printf("NO\n");

    return 0;
}
