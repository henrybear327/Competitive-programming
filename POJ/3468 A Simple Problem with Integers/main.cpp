#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;
typedef long long ll;

#define N 100010
#define lc(x) (2*x+1)
#define rc(x) (2*x+2)

ll inp[N];
ll *data = NULL, *lazy = NULL, n;
struct segmentTree {
	void init(int _size) {
		n = _size;
		if(data)
			free(data);
		if(lazy)
			free(lazy);

		int size = 2;
		while(_size >= size)
			size *= 2;
		size *= 2;

		data = (ll*)malloc(sizeof(ll) * size);
		lazy = (ll*)malloc(sizeof(ll) * size);
	}

	void build() {
		build(0, n - 1, 0);
	}

	void build(int l, int r, int idx) {
		// printf("%d %d %d\n", l, r, idx);
		lazy[idx] = 0;

		if(l == r) {
			data[idx] = inp[l];
			return;
		}

		int mid = l + (r - l) / 2;
		build(l, mid, lc(idx));
		build(mid + 1, r, rc(idx));

		data[idx] = data[lc(idx)] + data[rc(idx)];
	}

	// this type of segment tree: self is always up to date, children are not
	void push(int idx, int lb, int mid, int rb) {
		if(lazy[idx] != 0) {
			data[lc(idx)] += lazy[idx] * (mid - lb + 1); // stupid! You need to keep the child node updated!
			lazy[lc(idx)] += lazy[idx];

			data[rc(idx)] += lazy[idx] * (rb - (mid + 1) + 1); // stupid!
			lazy[rc(idx)] += lazy[idx];

			lazy[idx] = 0;
		}
	}

	void update(int l, int r, ll val) {
		update(0, n - 1, l, r, 0, val);
	}

	void update(int lb, int rb, int l, int r, int idx, ll val) {
		// printf("update %d %d %d %d %d %lld\n", lb, rb, l, r, idx, data[idx]);
		if(l > rb || r < lb)
			return;

		if(l <= lb && rb <= r) {
			data[idx] += val * (rb - lb + 1);
			lazy[idx] += val;
			return;
		}

		int mid = lb + (rb - lb) / 2;
		push(idx, lb, mid, rb);
		update(lb, mid, l, r, lc(idx), val);
		update(mid + 1, rb, l, r, rc(idx), val);
		data[idx] = data[lc(idx)] + data[rc(idx)];
	}

	ll query(int l, int r) {
		return query(0, n - 1, l, r, 0);
	}

	ll query(int lb, int rb, int l, int r, int idx) {
		// printf("%d %d %d %d %d %lld\n", lb, rb, l, r, idx, data[idx]);

		if(l > rb || r < lb)
			return 0;

		if(l <= lb && rb <= r) {
			return data[idx];
		}

		int mid = lb + (rb - lb) / 2;
		push(idx, lb, mid, rb);
		ll res = query(lb, mid, l, r, lc(idx)) + query(mid + 1, rb, l, r, rc(idx));
		data[idx] = data[lc(idx)] + data[rc(idx)];
		return res;
	}
} tree;

int main()
{
	int n, q;
	while(scanf("%d %d", &n, &q) == 2) {
		for(int i = 0; i < n; i++)
			scanf("%lld", &inp[i]);
		tree.init(n);
		tree.build();

		for(int i = 0; i < q; i++) {
			char cmd[10];
			scanf("%s", cmd);

			if(cmd[0] == 'C') {
				int l, r, val;
				scanf("%d %d %d", &l, &r, &val);

				tree.update(l - 1, r - 1, val);
			} else {
				int l, r;
				scanf("%d %d", &l, &r);
				printf("%lld\n", tree.query(l - 1, r - 1));
			}
		}
	}

	return 0;
}
