#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    
    int inp[n + 1];
    for(int i = 0; i < n; i++)
	scanf("%d", &inp[i + 1]);
    
    sort(inp + 1, inp + n + 1);

    long long ans = 0;
    for(int i = 1; i <= n; i++)
	ans += llabs(inp[i] - i);

    printf("%lld\n", ans);

    return 0;
}
