#include <bits/stdc++.h>
//LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    int m[1010][1010];
    memset(m, 0, sizeof(m));
    
    int ans = 0;
    for(int i = 0; i < n; i++) {
	int a, b;
	scanf("%d %d", &a, &b);

	m[a][b] = 1;
    }

    for(int a = 1; a <= 1000; a++) {
	for(int b = 1; b <= 1000; b++) {
	    if(m[a][b] == 1) {
		for(int k = 1; k <= 1000 && a + k <= 1000 && b + k <= 1000; k++)
		    ans += m[a + k][b + k] == 1 ? 1 : 0;
		for(int k = 1; k <= 1000 && a + k <= 1000 && b - k >= 1; k++)
		    ans += m[a + k][b - k] == 1 ? 1 : 0;
		for(int k = 1; k <= 1000 && a - k >= 1 && b + k <= 1000; k++)
		    ans += m[a - k][b + k] == 1 ? 1 : 0;
		for(int k = 1; k <= 1000 && a - k >= 1 && b - k >= 1; k++)
		    ans += m[a - k][b - k] == 1 ? 1 : 0;
	    }
	}
    }

    printf("%d\n", ans / 2);
    return 0;
}
