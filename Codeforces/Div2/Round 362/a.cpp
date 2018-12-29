#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, s, x;
    scanf("%d %d %d", &t, &s, &x);
    
    bool ok = false;
    if(x - t == 0)
	ok = true;
    if( (x - t) % s == 0 && (x - t) >= s)
	ok = true;
    if( (x - t - 1) % s == 0 && (x - t - 1) >= s)
	ok = true;

    if(ok)
	printf("YES\n");
    else
	printf("NO\n");

    return 0;
}
