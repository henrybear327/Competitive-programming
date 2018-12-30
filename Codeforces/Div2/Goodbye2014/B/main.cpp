#include <bits/stdc++.h>

using namespace std;

vector<int> g[333], group;
bool seen[333];
void dfs(int u)
{
	if(seen[u] == true)
		return;
	seen[u] = true;
	for(auto v : g[u]) {
		dfs(v);
	}
	group.push_back(u);
}


int main()
{
	int n;
	scanf("%d", &n);

	int inp[n];
	for(int i = 0; i < n; i++)
		scanf("%d", &inp[i]);

	for(int i = 0; i < n; i++) {
		char str[n + 10];
		scanf("%s", str);
		for(int j = 0; j < n; j++) 
			if(str[j] == '1')
				g[i].push_back(j);
	}

	memset(seen, false, sizeof(seen));
	for(int i = 0; i < n; i++) {
		if(seen[i] == false) {
			group.clear();
			dfs(i);

			vector<int> num;
			for(auto j : group)
				num.push_back(inp[j]);
			sort(num.begin(), num.end());
			sort(group.begin(), group.end());
			
			int idx = 0;
			for(auto j : group)
				inp[j] = num[idx++];
		}
	}

	for(auto i : inp)
		printf("%d ", i);

	return 0;
}
