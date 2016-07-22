#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int main()
{
    int n;
    scanf("%d", &n);

    if(n == 0)
	printf("0 0 0\n");
    else if(n == 1)
	printf("1 0 0\n");
    else {
	ll fib[100];
	fib[0] = 0;
	fib[1] = fib[2] = 1;
	for(int i = 3; i < 100; i++) {
	    fib[i] = fib[i - 1] + fib[i - 2];
	    // printf("%lld\n", fib[i]);
	    if(fib[i] == n) {
		printf("%lld %lld %lld\n", 0LL, fib[i - 1], fib[i - 2]);
		break;
	    }
	}
    }

    return 0;
}
