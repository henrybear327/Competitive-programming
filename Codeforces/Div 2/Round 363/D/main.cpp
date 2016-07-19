#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

struct {
    int par[200100];
    void init() {
	memset(par, -1, sizeof(par));
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
} UFDS;

int main()
{
    UFDS.init();
    int n;
    scanf("%d", &n);

    int inp[n + 1], orig[n + 1];
    for(int i = 1; i <= n; i++) {
	scanf("%d", &inp[i]);
	orig[i] = inp[i];
    }
    
    int selfLoop = -1;
    for(int i = 1; i <= n; i++)
	if(inp[i] == i) 
	    selfLoop = i;
	
    // either have self loop or cycle

    // connect all self loops together
    // one tree will only have one self loop
    for(int i = 1; selfLoop != -1 && i <= n; i++)
	if(inp[i] == i && i != selfLoop)
	    inp[i] = selfLoop;
    
    for(int i = 1; i <= n; i++) {
	if(selfLoop == -1) {
	    if(UFDS.root(i) == UFDS.root(inp[i])) {
		inp[i] = selfLoop = i;
	    } else {
		UFDS.merge(i, inp[i]);
	    }
	} else {
	    if(UFDS.root(i) == UFDS.root(inp[i])) {
		inp[i] = selfLoop;
	    } else {
		UFDS.merge(i, inp[i]);
	    }
	}
    }	
    
    int ans = 0;
    for(int i = 1; i <= n; i++)
	if(orig[i] != inp[i])
	    ans++;
    
    printf("%d\n", ans);
    for(int i = 1; i <= n; i++)
	printf("%d%c", inp[i], i == n ? '\n' : ' ');
    
    return 0;
}
