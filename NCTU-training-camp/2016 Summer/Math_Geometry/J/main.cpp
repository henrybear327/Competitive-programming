#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x, y, r;
    scanf("%d %d %d", &x, &y, &r);

    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    
    double dx = a - x;
    double dy = b - y;
    double d = sqrt(dx * dx + dy * dy);

    if(c > r) {
	swap(x, a);
	swap(y, b);
	swap(r, c);
    }
    
    // r > c
    if(r + c < d)
	printf("%.15f\n", (d - r - c) / 2);
    else {
	if( (r - c) - d <= 0)
	    printf("0\n");
	else
	    printf("%.15f\n", ((r - c) - d) / 2);
    }

    return 0;
}
