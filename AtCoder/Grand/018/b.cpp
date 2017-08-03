#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	int l[n][m];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) {
			scanf("%d", &l[i][j]);
			l[i][j]--;
		}
	
	for(int i = 1; i <= n; i++) {
		vector<int> cnt[m];
		int choice[n];
		fill(choice, choice + n, 0);
		bool lock[m];
		memset(lock, 0, sizeof(lock));

		queue<int> q;
		for(int j = 0; j < n; j++)
			q.push(j);
		
		bool ok = true;
		while(!q.empty()) {
			int cur = q.front();
			q.pop();

			while(choice[cur] < m) {
				int next = l[cur][choice[cur]];
				if(lock[next] == true)
					choice[cur]++;
				else
					break;
			}

			if(choice[cur] == m) {
				ok = false;
				break;
			}	
			
			int next = l[cur][choice[cur]];
			cnt[next].push_back(cur);
			if((int)cnt[next].size() > i) {
				for(auto j : cnt[next]) {
					q.push(j);
					lock[next] = true;
				}
			}			
		}

		if(ok) {
			printf("%d\n", i);
			break;
		}
	}

	return 0;
}
