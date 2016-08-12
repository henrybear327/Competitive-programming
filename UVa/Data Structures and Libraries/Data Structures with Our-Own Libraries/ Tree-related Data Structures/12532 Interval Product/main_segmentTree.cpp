#include <bits/stdc++.h>

using namespace std;

#define N 100010

#define lc(x) (2*x+1)
#define rc(x) (2*x+2)
struct {
	int data[1 << 18], n; // size = (nearest power of 2) * 2 
	void build(int n, int inp[]) {
		build(0, 0, n - 1, inp); // [l, r]
		this->n = n;
	}

	void build(int idx, int l, int r, int inp[]) {
		// printf("%d %d %d\n", idx, l, r);
		if(l == r) {
			data[idx] = inp[l];
			return;
		}

		build(lc(idx), l, (l + r) / 2, inp);
		build(rc(idx), (l + r) / 2 + 1, r, inp);

		data[idx] = data[lc(idx)] * data[rc(idx)];
	}

	int query(int l, int r) { // [l, r] 0-based
		return query(0, 0, n - 1, l, r); 
	}

	int query(int idx, int lb, int rb, int l, int r) {
		if(l == lb && r == rb) {
			return data[idx];
		}

		int mid = (lb + rb) / 2;
		if(l <= mid && r <= mid)
			return query(lc(idx), lb, mid, l, r);
		else if(l > mid && r > mid) 
			return query(rc(idx), mid + 1, rb, l, r);
		else
			return query(lc(idx), lb, mid, l, mid) * query(rc(idx), mid + 1, rb, mid + 1, r);
	}

	void update(int pos, int val) {
		update(0, 0, n - 1, pos, val);
	}

	void update(int idx, int l, int r, int pos, int val) {
		if(l == r && l == pos) {
			data[idx] = val;
			return;
		}
		
		int mid = (l + r) / 2;
		if(l <= pos && pos <= mid) 
			update(lc(idx), l, mid, pos, val);
		else
			update(rc(idx), mid + 1, r, pos, val);

		data[idx] = data[lc(idx)] * data[rc(idx)];
	}

	void print(int n) {
		for(int i = 0; i < n; i++) {
			printf("%d: %d\n", i, data[i]);
		}
		printf("\n");
	}
} tree;

int main()
{
	int n, q;
	while(scanf("%d %d", &n, &q) == 2) {
		int inp[n];
		for(int i = 0; i < n; i++) {
			scanf("%d", &inp[i]);

			if(inp[i] > 0)
				inp[i] = 1;
			else if(inp[i] < 0)
				inp[i] = -1;
		}

		// build segment tree
		// printf("Building...\n");
		tree.build(n, inp);
		// printf("Built...\n");

		//tree.print(7);

		// take queries
		for(int i = 0; i < q; i++) {
			char inp[100];
			scanf("%s", inp);

			if(inp[0] == 'C') {
				// change
				int pos, val;
				scanf("%d %d", &pos, &val);
				pos--;

				if(val < 0)
					val = -1;
				else if(val > 0)
					val = 1;

				tree.update(pos, val);
			} else {
				// query
				int l, r;
				scanf("%d %d", &l, &r);

				l--;
				r--;
				// printf("%d\n", tree.query(l, r));
				
				int res = tree.query(l, r);
				printf("%c", res == 0 ? '0' : (res > 0 ? '+' : '-'));
			}
			
			// tree.print(7);
		}
		printf("\n");
	}	

	return 0;
}
