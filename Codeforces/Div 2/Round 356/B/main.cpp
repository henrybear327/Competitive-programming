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
    int n, pos;
    scanf("%d %d", &n, &pos);
    pos--;

    int inp[n];
    for(int i = 0; i < n; i++)
	scanf("%d", &inp[i]);

    int md = min(pos - 0, n - pos - 1);
    
    int ans = 0;
    for(int i = 0; (pos + i < n) || (pos - i) >= 0; i++) {
	if(i == 0) {
	    ans += inp[pos];
	    continue;
	}

	if(i > md) {
	    if(pos + i < n) {
		ans += inp[pos + i];
	    } else {
		ans += inp[pos - i];
	    }
	} else {
	    if(inp[pos + i] == 1 && inp[pos - i] == 1)
		ans += 2;
	}
    }
    printf("%d\n", ans);

    return 0;
}
