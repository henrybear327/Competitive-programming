#include <bits/stdc++.h>

using namespace std;

#define N 1000010*4 // Be careful

struct node {
	int tot, left, right;
} data[N];

char inp[N];
int len, q;

#define lc(x) (x*2+1)
#define rc(x) (x*2+2)
struct tree { // sigh
	void build() {
		build(0, len - 1, 0);
	}

	void build(int l, int r, int node) { //[l, r]
		if(l < 0 || r > N || node < 0 || node > N) {
			printf("Bitch\n");
			exit(1);
		}
		if(l == r) {
			data[node].tot = 0;
			data[node].left = (inp[l] == '(');
			data[node].right = (inp[l] == ')');
			return;
		}

		int mid = (l + r) / 2;
		build(l, mid, lc(node)); // build left subtree
		build(mid + 1, r, rc(node)); // build right subtree

		// merge data
		int newMatch = min(data[lc(node)].left, data[rc(node)].right);
		data[node].tot = data[lc(node)].tot + data[rc(node)].tot + newMatch;

		data[node].left = data[lc(node)].left + data[rc(node)].left - newMatch;
		data[node].right = data[lc(node)].right + data[rc(node)].right - newMatch;
	}

	int query(int l, int r) {
		struct node res = query(l, r, 0, len - 1, 0);
		return res.tot;
	}
	struct node query(int l, int r, int le, int re, int node) { // l, r, leftEnd, rightEnd, node
		// printf("%d %d %d %d %d\n", l, r, le, re, node);

		if(l > r || l < le || r > re || node < 0 || node > N || le > re) {
			printf("%d %d\n", l, r);
		}

		if(l == le && r == re) {
			return data[node];
		} else {
			int mid = (le + re) / 2;
			if(l <= mid && mid + 1 <= r) {
				struct node left = query(l, mid, le, mid, lc(node));
				struct node right = query(mid + 1, r, mid + 1, re, rc(node));
				struct node res = {0, 0, 0};
				int mn = min(left.left, right.right);
				res.tot = left.tot + right.tot + mn;
				res.left = left.left + right.left - mn;
				res.right = left.right + right.right - mn;

				return res;
			} else if(r <= mid) {
				return query(l, r, le, mid, lc(node));
			} else { // l >= mid + 1
				return query(l, r, mid + 1, re, rc(node));
			}
		}
	}
	void print() {
		for(int i = 0; i < 32; i++) {
			printf("%d %d %d %d\n", i, data[i].tot, data[i].left, data[i].right);
		}
		printf("\n");
	}
} SegmentTree;

int main()
{
	scanf("%s", inp);

	scanf("%d", &q);

	len = strlen(inp);
	SegmentTree.build();

	for(int i = 0; i < q; i++) {
		int l, r;
		scanf("%d %d", &l, &r); // [l, r]
		l--;
		r--;

		printf("%d\n", SegmentTree.query(l, r) * 2);
	}

	return 0;
}
