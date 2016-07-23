#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int main()
{
    int n;
    scanf("%d", &n);
    
    ll inp[n], sum = 0;
    for(int i = 0; i < n; i++) 
	scanf("%lld", &inp[i]), sum += inp[i];
    
    sort(inp, inp + n);
    
    printf("%lld\n", inp[n - 1] - (sum - inp[n - 1]) + 1);

    return 0;
}
