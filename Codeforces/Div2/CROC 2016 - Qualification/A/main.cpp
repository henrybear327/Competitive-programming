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
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    int g[a][b];
    memset(g, 0, sizeof(g));

    int cnt = 1;
    for(int i = 0; i < a; i++) {
		for(int j = 0; j < b; j++) {
		    g[i][j] = cnt > n ? 0 : cnt++;
		}
		if(b % 2 == 0 && i % 2 == 1) {
		    reverse(g[i], g[i] + b);
		}
    }

    if(cnt != n + 1)
	printf("-1\n");
    else
	for(int i = 0; i < a; i++) {
	    for(int j = 0; j < b; j++) {
		printf("%d%c", g[i][j], j == b - 1 ? '\n' : ' ');
	    }
	}

    return 0;
}
