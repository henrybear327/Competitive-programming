#include <cstdio>
#include <algorithm>

using namespace std;

/* 
Plain Union-find data structure
*/

#define MAX_ELEMEMT 50010
int par[MAX_ELEMEMT];
void init()
{
    for(int i = 0; i < MAX_ELEMEMT; i++)
	par[i] = -1;
}

int root(int x)
{
    return par[x] < 0 ? x : par[x] = root(par[x]);
}

void merge(int x, int y)
{
    if(root(x) != root(y)) {
	if(par[root(y)] < par[root(x)])
	    swap(x, y);
	par[root(x)] += par[root(y)];
	par[root(y)] = root(x);
    }
}

int main()
{
    int n, m, cnt = 1;
    while(scanf("%d %d", &n, &m) == 2 && (n || m)) {
	init();
	for(int i = 0; i < m; i++) {
	    int a, b;
	    scanf("%d %d", &a, &b);

	    merge(a, b);
	}

	int ans = 0;
	for(int i = 1; i <= n; i++) {
	    root(i);
	    if(par[i] < 0)
		ans++;
	}
	printf("Case %d: %d\n", cnt++, ans);
    }

    return 0;
}
