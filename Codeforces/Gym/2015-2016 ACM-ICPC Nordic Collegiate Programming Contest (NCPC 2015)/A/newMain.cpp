#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

#define N 100010
vector<int> g[N];
bool seen[N];
vector<int> group;
void dfs(int u) 
{
	if(seen[u])
		return;
	seen[u] = true;
	group.push_back(u);
	for(auto i : g[u]) {
		dfs(i);
	}
}


int diameter = 0, radius[N], deg[N];
int findRadius(int u)
{
	// add all leaves to queue
	group.clear();
	dfs(u);

	queue<int> q;
	for(auto i : group) 
		if(deg[i] == 1) 
			q.push(i);

	// tree center algo
	int mx = 0;
	while(q.empty() == false) {
		int u = q.front();
		q.pop();

		for(int v : g[u]) {
			deg[v]--;
			if(deg[v] == 1) {
				q.push(v);
				radius[v] = radius[u] + 1;
				mx = max(mx, radius[v]);
			}
		}
	}

	int cnt = 0;
	for(auto j : group) 
		if(radius[j] == mx)
			cnt++;

	diameter = max(diameter, mx * 2 + (cnt == 2) ); // diameter = radius * 2 + 1 (if the diameter has even numbers of nodes)
	return mx + (cnt == 2); // radius needs to add 1 if there are 2 centers
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	if(m == 0) {
		int ans;
		if(n == 1)
			ans = 0;
		else if(n == 2)
			ans = 1;
		else
			ans = 2;
		printf("%d\n", ans);

		return 0;
	}

	for(int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);

		g[u].push_back(v);
		g[v].push_back(u);
		deg[u]++;
		deg[v]++;
	}

	// find tree center for every group
	memset(seen, false, sizeof(seen));
	vector<int> radiusList;
	for(int i = 0; i < n; i++) {
		if(seen[i] == false) {	
			radiusList.push_back(findRadius(i));
		}
	}

	sort(radiusList.begin(), radiusList.end());
	reverse(radiusList.begin(), radiusList.end());
	// Three cases: diameter, 1st + 2nd radius + 1 (1 connection edge), and 2nd + 3rd radius + 2 (2 connection edges)
	if(radiusList.size() == 1)
		printf("%d\n", diameter);
	else 
		printf("%d\n", max(diameter, max(radiusList[0] + radiusList[1] + 1, radiusList.size() > 2 ? radiusList[1] + radiusList[2] + 2 : 0)));

	return 0;
}
