#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);

    int inp[7];
    for(int i = 1; i <= 6; i++)
	scanf("%d", &inp[i]);
    
    int ans = 0;
    if(a > x)
	ans += inp[6];
    if(a < 0)
	ans += inp[5];
    if(b > y)
	ans += inp[2];
    if(b < 0)
	ans += inp[1];
    if(c > z)
	ans += inp[4];
    if(c < 0)
	ans += inp[3];

    printf("%d\n", ans);
    
    return 0;
}
