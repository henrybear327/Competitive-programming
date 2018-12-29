#include <bits/stdc++.h>
//LLONG_MIN LLONG_MAX INT_MIN INT_MAX

using namespace std;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}   

int main()
{
    int n;
    scanf("%d", &n);

    int inp[n];
    for(int i = 0; i < n; i++) {
	scanf("%d", &inp[i]);
    }
    
    int ans = inp[0];
    for(int i = 1; i < n; i++) {
	ans = gcd(ans, inp[i]);
    }

    printf("%d\n", ans * n);

    return 0;
}
