#include <bits/stdc++.h>
//LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

typedef long long int ll;

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    
    int inp[n];
    for(int i = 0; i < n; i++)
	scanf("%d", &inp[i]);
    
    sort(inp, inp + n);
    int ans = 1;
    for(int i = 0; i < n; i++) {
	if(inp[i] >= ans)
	    ans++;
	else if(inp[i] == ans - 1)
	    continue;
	else
	    break;
    }

    printf("%d\n", ans);

    return 0;
}
