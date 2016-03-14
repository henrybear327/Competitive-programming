#include <bits/stdc++.h>
//LLONG_MIN LLONG_MAX INT_MIN INT_MAX

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    int has[33] = {0}, idx = 1;
    while(n) {
	if(n & 1)
	    has[idx] = 1;
	idx++;
	n >>= 1;
    }

    for(int i = idx - 1; i >= 1; i--) {
	if(has[i]) {
	    printf("%d ", i);
	}	
    }

    return 0;
}
