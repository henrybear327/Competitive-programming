#include <bits/stdc++.h>

using namespace std;

#define N 100010
#define lsb(x) (x&(-x))

typedef long long ll;
ll global_inc; // crucial idea

struct {
	ll data[N];
	int n;
	void init(int n) {
		memset(data, 0, sizeof(data));
		this->n = n;
	}

	void add(int i, ll val) {
		while(i <= n) {
			data[i] += val;
			i += lsb(i);
		}
	}

	ll query(int i) {
		ll res = 0;
		while(i > 0) {
			res += data[i];
			i -= lsb(i);
		}
		return res;
	}

	void print() {
		for(int i = 0; i <= n; i++)
			printf("%lld%c", data[i], i == n ? '\n' : ' ');
	}
} BIT;

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	BIT.init(n);
	global_inc = 0;

	for(int i = 1; i <= n; i++) {
		ll num;
		scanf("%lld", &num);

		BIT.add(i, num);
	}

	for(int i = 0; i < m; i++) {
		int op;
		scanf("%d", &op);

		if(op == 1) {
			int pos;
			ll val;
			scanf("%d %lld", &pos, &val);
			ll prev = BIT.query(pos) - BIT.query(pos - 1) + global_inc;
			prev = val - prev;
			BIT.add(pos, prev);
		} else if(op == 2) {
			ll num;
			scanf("%lld\n", &num);

			global_inc += num;
		} else {
			int pos;
			scanf("%d", &pos);
			printf("%lld\n", BIT.query(pos) - BIT.query(pos - 1) + global_inc);
		}

		// BIT.print();
	}

	return 0;
}
