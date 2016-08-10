#include <bits/stdc++.h>

using namespace std;

#define N 100010
#define LSB(x) (x&(-x))

#define DEBUG 0

int inp[N];
set<int> zero;
int n, m;
vector<char> ans;

struct {
	int data[N];
	void init() {
		fill(data, data + N, 0); // neg count
	}

	void build(int p, int v) {
		while(p <= n) {
			data[p] += (v == -1 ? 1 : 0);
			p += LSB(p);
		}
	}

	void update(int p, int v) {
		while(p <= n) {
			data[p] += v;
			p += LSB(p);
		}
	}

	void print() {
		for(int i = 0; i <= n; i++)
			printf("%d%c", data[i], i == n ? '\n' : ' ');
	}

	void query(int l, int r) { // [l, r]
		int res = query(r) - query(l - 1);
		int pos = -1;
		if(zero.upper_bound(l - 1) != zero.end())
			pos = *zero.upper_bound(l - 1);

		if(l <= pos && pos <= r) {
			ans.push_back('0');	
			return;
		}

		if(res % 2 == 0)
			ans.push_back('+');
		else
			ans.push_back('-');
	}

	int query(int p) {
		int res = 0;
		while(p > 0) {
			res += data[p];
			p -= LSB(p);
		}
		return res;
	}
} bit;

int main()
{
	while(scanf("%d %d", &n, &m) == 2) {
		zero.clear();
		bit.init();
		ans.clear();

		for(int i = 1; i <= n; i++) {
			scanf("%d", &inp[i]);
			if(inp[i] == 0) {
				zero.insert(i);
			} else {
				if(inp[i] > 0)
					inp[i] = 1;
				else
					inp[i] = -1;

				// printf("%d %d\n", i, inp[i]);
				bit.build(i, inp[i]);
			}
			// bit.print();
		}

		// printf("start\n");
		for(int i = 0; i < m; i++) {
			char c[100];
			scanf("%s", c);

			if(c[0] == 'C') {
				int pos, val;

				scanf("%d %d", &pos, &val);

				if(val > 0)
					val = 1;
				else if(val < 0)
					val = -1;

				if(val == 0) {
					zero.insert(pos);

					if(inp[pos] < 0)
						bit.update(pos, 1);
					inp[pos] = val;

					// bit.print();
					continue;
				} 

				if(inp[pos] == 0) {
					zero.erase(pos);
					bit.build(pos, val);

					// bit.print();
					continue;
				} 
				
				if(inp[pos] * val < 0)
					bit.update(pos, -val);

				inp[pos] = val;
			} else {
				int l, r;
				scanf("%d %d", &l, &r);

				bit.query(l, r);
			}
			
			//bit.print();
		}
		for(auto i : ans)
			printf("%c", i);
		printf("\n");
	}

	return 0;
}
