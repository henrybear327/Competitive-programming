#include <bits/stdc++.h>

using namespace std;

int main()
{   
    int n;
    scanf("%d", &n);
    
    if(n == 1 || n == 2)
	printf("1\n");
    else {
	int cnt = 2 * (n / 3);
	n %= 3;
	if(n == 1 || n == 2)
	    cnt++;
	printf("%d\n", cnt);
    }

    return 0;
}
