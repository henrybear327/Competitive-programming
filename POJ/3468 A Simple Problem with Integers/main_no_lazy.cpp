#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;
typedef long long ll;

#define N 100010
int inp[N];
ll *tree, *lazy;

void init() // malloc the space for tree pointer
{
    int depth = 1;
    while( (1 << depth++) < N);
    
    tree = (ll*) malloc((1 << depth) * sizeof(ll));
    lazy = (ll*) malloc((1 << depth) * sizeof(ll));
}

#define lc(x) (x << 1)
#define rc(x) ((x << 1) + 1)
struct SegmentTree {
    int nn;
    void init(int n) 
    {
	nn = n;
	int depth = 1;
	while( (1 << depth++) < n);

	build(1, 0, n - 1);
    }

    void build(int idx, int l, int r)  // [l, r] = [0, n - 1]
    {
	if(l == r) {
	    tree[idx] = inp[l];
	    return;
	}

	int mid = (l + r) / 2;
	build(lc(idx), l, mid);
	build(rc(idx), mid + 1, r);
	
	lazy[idx] = 0;
	tree[idx] = tree[lc(idx)] + tree[rc(idx)];
    }
    
    ll query(int i, int j)
    {
	return query(1, 0, nn - 1, i, j);
    }

    ll query(int idx, int l, int r, int i, int j)
    {
	if(l == i && r == j) {
	    return tree[idx];
	}

	int mid = (l + r) / 2;
	if(i <= mid && mid + 1 <= j) {
	    return query(lc(idx), l, mid, i, mid) + query(rc(idx), mid + 1, r, mid + 1, j);
	} else if(j <= mid) {
	    return query(lc(idx), l, mid, i, j);
	} else {
	    return query(rc(idx), mid + 1, r, i, j);
	}
    }

    void update(int i, int j, ll val)
    {
	update(1, 0, nn - 1, i, j, val);
    }

    void update(int idx, int l, int r, int i, int j, ll val)
    {
	//  printf("%d %d %d %d %d %lld\n", idx, l, r, i, j, val);
	if(l == r) { // NOT i == j
	    tree[idx] += val;
	    return;
	}

	int mid = (l + r) / 2;
	if(i <= mid && mid + 1 <= j) {
	    update(lc(idx), l, mid, i, mid, val);
	    update(rc(idx), mid + 1, r, mid + 1, j, val);
	} else if(j <= mid) {
	    update(lc(idx), l, mid, i, j, val);
	} else {
	    update(rc(idx), mid + 1, r, i, j, val);
	}

	tree[idx] = tree[lc(idx)] + tree[rc(idx)];
    }
};

int main()
{
    init();

    int n, q;
    while(scanf("%d %d", &n, &q) == 2) {
	for(int i = 0; i < n; i++) 
	    scanf("%d", &inp[i]);

	SegmentTree sum;
	sum.init(n);

	for(int i = 0; i < q; i++) {
	    char com[100];
	    int a, b;
	    scanf("%s %d %d", com, &a, &b);
	    a--;
	    b--;

	    if(com[0] == 'Q') {
		printf("%lld\n", sum.query(a, b));
	    } else {
		int val;
		scanf("%d", &val);
		sum.update(a, b, val);
	    }

	    /*
	    for(int i = 0; i < n; i++)
		printf("%lld ", sum.query(i, i)); 
	    printf("\n");
	    */
	}
    }

    return 0;
}
