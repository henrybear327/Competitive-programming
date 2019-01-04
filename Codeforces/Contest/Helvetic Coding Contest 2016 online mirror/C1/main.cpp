#include <bits/stdc++.h>
//LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

typedef long long int ll;

using namespace std;

struct UFDS {
    int par[1111];

    void init() {
	for(int i = 0; i < 1111; i++) {
	    par[i] = -1;
	}
    }

    int root(int x) {
	return par[x] < 0 ? x : par[x] = root(par[x]);
    }

    void merge(int x, int y) {
	x = root(x);
	y = root(y);

	if(x == y)
	    return;

	if(par[x] > par[y]) 
	    swap(x, y);
	par[x] += par[y];
	par[y] = x;
    }
} uf;

int main()
{
    uf.init();

    int n, k;
    scanf("%d %d", &n, &k);
    
    if(k != n - 1) {
	printf("no\n");
	return 0;
    }

    for(int i = 0; i < k; i++) {
	int u, v;
	scanf("%d %d", &u, &v);

	uf.merge(u, v);
    }
    
    int t = uf.root(1);
    for(int i = 1; i <= n; i++) {
	if(uf.root(i) != t) {
	    printf("no\n");
	    return 0;
	}
    }
    
    printf("yes\n");

    return 0;
}
