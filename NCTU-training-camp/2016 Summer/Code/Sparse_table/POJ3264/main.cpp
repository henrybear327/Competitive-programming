#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

struct {
    int mn[16][50010];
    int mx[16][50010];

    void build(int inp[], int n) {
	for(int j = 0; j < n; j++) {
	    mn[0][j] = inp[j];
	    mx[0][j] = inp[j];
	}

	for(int i = 1; (1 << i) <= n; i++) 
	    for(int j = 0; j + (1 << i) <= n; j++) {
		mn[i][j] = min(mn[i - 1][j], mn[i - 1][j + (1 << (i - 1))]);
		mx[i][j] = max(mx[i - 1][j], mx[i - 1][j + (1 << (i - 1))]);
	    }
    }

    int query(int l, int r) { // [l, r)
	int k = floor(log2(r - l));

	int minn = min(mn[k][l], mn[k][r - (1 << k)]);
	int maxx = max(mx[k][l], mx[k][r - (1 << k)]);
	return maxx - minn;
    }
} sp;

int main()
{
    int n, m;
    while(scanf("%d %d", &n, &m) == 2) {
	int inp[n];
	for(int i = 0; i < n; i++)
	    scanf("%d", &inp[i]);
	
	sp.build(inp, n);
	
	for(int i = 0; i < m; i++) {
	    int l, r;
	    scanf("%d %d", &l, &r);

	    printf("%d\n", sp.query(l - 1, r));
	}
    }

    return 0;
}
