#include <bits/stdc++.h>

using namespace std;

int n;
int ans[13], inp[13];
bool used[13];
void dfs(int depth, int start)
{
	if(depth == 6) {
		for(int i = 0; i < 6; i++)
			printf("%d%c", ans[i], i == 5 ? '\n' : ' ');
		return;
	}

	for(int i = start; i < n; i++) {
		if(used[i] == false) {
			used[i] = true;
			ans[depth] = inp[i];
			dfs(depth + 1, i + 1);
			used[i] = false;
		}
	}
}	


int main()
{
	memset(used, false, sizeof(used));
	bool first = true;
	while(scanf("%d", &n) == 1 && n) {
		if(first)
			first = false;
		else
			printf("\n");

		for(int i = 0; i < n; i++)
			scanf("%d", &inp[i]);
		sort(inp, inp + n);
		dfs(0, 0);
	}

	return 0;
}
