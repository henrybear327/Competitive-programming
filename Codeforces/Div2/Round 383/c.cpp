#include <bits/stdc++.h>

using namespace std;

int size;

vector<int> g[111];
int start;
bool flag;
void dfs(int u, bool seen[])
{
	if(seen[u] == true && u == start) {
		flag = true;
		return;
	}
	if(seen[u] == true)
		return;
	size++;
	seen[u] = true;

	for(auto i : g[u])
		dfs(i, seen);
}

long long gcd(long long a, long long b)
{
	return a == 0 ? b : gcd(b % a, a);
}

int main()
{
	int n;
	scanf("%d", &n);

	for(int i = 1; i <= n; i++) {
		int v;
		scanf("%d", &v);
		g[i].push_back(v);
	}

	bool seen[n + 1];
	memset(seen, false, sizeof(seen));

	vector<int> loopSz;
	bool error = false;
	for(int i = 1; i <= n; i++) {
		if(seen[i] == false) {
			size = 0;
			start = i;
			flag = false;
			dfs(i, seen);

			if(flag)
				loopSz.push_back(size % 2 == 0 ? size / 2 : size);
			else
				error = true;
		}
	}

	if(loopSz.size() == 0 || error)
		printf("-1\n");
	else {
		long long lcm = loopSz[0];
		for(int i = 1; i < (int)loopSz.size(); i++) {
			lcm = lcm / gcd(lcm, loopSz[i]) * loopSz[i];
		}

		printf("%lld\n", lcm);
	}

	return 0;
}
