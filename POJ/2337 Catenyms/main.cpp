#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

typedef pair<int, int> ii;

vector<ii> g[26];

int main()
{
	int ncase;
	scanf("%d", &ncase);

	while(ncase--) {
		int n;
		scanf("%d", &n);
		for(int i = 0; i < 26; i++)
			g[i].clear();

		for(int i = 0; i < n; i++) {
			char inp[1000];
			scanf("%s", inp);

			int len = strlen(inp);
			char u = inp[0], v = inp[len - 1];
		}
	}

	return 0;
}
