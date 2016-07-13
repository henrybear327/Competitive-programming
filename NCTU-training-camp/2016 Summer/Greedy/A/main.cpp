#include <cstdio>

int gcd(int a, int b)
{
    return a == 0 ? b : gcd(b % a , a);
}

int main()
{
    int n;
    scanf("%d", &n);
    
    int ans = -1;
    for(int i = 0; i < n; i++) {
	int tmp;
	scanf("%d", &tmp);
	
	ans = ans == -1 ? tmp : gcd(ans, tmp);
    }

    printf("%d\n", ans * n);

    return 0;
}
