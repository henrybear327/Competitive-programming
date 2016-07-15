#include <cstdio>

#define M 1000000007
int main()
{
    int n;
    scanf("%d", &n);
    
    if(n == 1)
	printf("0\n");
    else {
	long long prev = 0;
	long long ans = 0;
	long long base = 3;
	for(int i = 2; i <= n; i++) {
	    ans = (base - prev + M) % M;
	    base = (base * 3) % M;
	    prev = ans;
	}

	printf("%lld\n", ans);
    }
    
    return 0;
}
