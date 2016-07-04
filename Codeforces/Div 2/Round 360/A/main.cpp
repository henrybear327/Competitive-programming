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
    int n, d;
    scanf("%d %d", &n, &d);
    
    int prev = 0, ans = 0;
    // can simply use counting and update method
    for(int i = 0; i < d; i++) {
	char inp[n + 2];
	scanf("%s", inp);
	
	int cnt = 0;
	for(int j = 0; j < n; j++) {
	    if(inp[j] == '1')
		cnt++;
	}
	if(cnt == n) {
	    ans = max(ans, i - prev);
	    prev = i + 1;
	}
    }

    ans = max(ans, d - prev);
    printf("%d\n", ans);

    return 0;
}
