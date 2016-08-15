#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

#define N 100100
int t;
bool seen[N];
int in[N], out[N];

// vector<int> g[N];
vector< vector<int> > g(N);

#define lsb(x) (x & (-x))
struct BIT {
	int data[N * 2], n;
	void init(int _n) {
		memset(data, 0, sizeof(data));
		n = _n;
	}

	void add(int p, int v) {
		while(p <= n) {
			data[p] += v;
			p += lsb(p);
		}
	}

	int query(int p) {
		int res = 0;
		while(p > 0) {
			res += data[p];
			p -= lsb(p);
		}
		return res;
	}
} bit;

void dfs(int u) 
{
	seen[u] = true;

	in[u] = t++;

	for(int i = 0; i < (int)g[u].size(); i++) {
		int v = g[u][i];
		if(!seen[v])
			dfs(v);
	}

	out[u] = t++;
}

int main()
{
	int n;
	while(scanf("%d", &n) == 1) {
		g.clear();

		bit.init(n * 2);

		for(int i = 0; i < n - 1; i++) {
			int a, b;
			scanf("%d %d", &a, &b);

			g[a].push_back(b);
			// g[b].push_back(a);
		}		
		
		t = 1;
		memset(seen, false, sizeof(seen));
		dfs(1);
		
		bool hasApple[N];
		for(int i = 1; i <= 2 * n; i++) {
			bit.add(i, 1);
		}

		fill(hasApple, hasApple + n + 1, true);

		int q;
		scanf("%d", &q);
		for(int i = 0; i < q; i++) {
			char inp[100];
			int x;
			scanf("%s %d", inp, &x);

			if(inp[0] == 'Q') {
				printf("%d\n", ( bit.query(out[x]) - bit.query(in[x] - 1) ) / 2);
			} else {
				if(hasApple[x]) {
					bit.add(in[x], -1);
					bit.add(out[x], -1);
				} else {
					bit.add(in[x], 1);
					bit.add(out[x], 1);
				}
				hasApple[x] = !hasApple[x];
			}
		}
	}

	return 0;
}
