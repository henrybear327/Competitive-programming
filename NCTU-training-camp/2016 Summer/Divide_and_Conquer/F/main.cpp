#include <bits/stdc++.h>

using namespace std;

int inp[5555], n;

int vertical(int l, int r) // [l, r] -> [3, 5] -> 5 - 3 + 1
{
    return r - l + 1;
}   

int horizontal(int l, int r) {
    int res = INT_MAX;
    for(int i = l; i <= r; i++)
	res = min(res, inp[i]);
    
    return res;
}

int calculate(int l, int r) // [l, r]
{
    // process the tile by case
    int res = 0;

    int ver = vertical(l, r);
    int hor = horizontal(l, r);
    res += min(ver, hor);

    if(ver <= hor) // take the whole tile away
	for(int j = l; j <= r; j++)
	    inp[j] = 0;
    else
	for(int j = l; j <= r; j++) 
	    inp[j] -= hor;
    
    // process the remaining consecutive tiles
    for(int i = l; i <= r; i++) {
	if(inp[i] > 0) {
	    for(int j = i; j <= r; j++) {
		if(inp[j] == 0) {
		    res += calculate(i, j - 1);
		    break;
		} else if(j == r) {
		    res += calculate(i, j);
		    break;
		}
	    }
	}   
    }
    return min(res, r - l + 1);
}

int main()
{   
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
	scanf("%d", &inp[i]);

    printf("%d\n", calculate(0, n - 1));

    return 0;
}
