#include <cstdio>
#include <vector>

using namespace std;
typedef pair<int, int> ii;

vector<ii> g[11111];

int n, k;
void input()
{	
	for(int i = 0; i <= n; i++) 
		g[i].clear();

	for(int i = 0; i < n; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);

		g[u].push_back(ii(v, w));
		g[v].push_back(ii(u, w));
	}
}

int main()
{
	while(scanf("%d %d", &n, &k) == 2 && (n || k)) {
		input();
	}

	return 0;
}
