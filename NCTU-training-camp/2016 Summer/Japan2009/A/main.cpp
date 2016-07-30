#include <bits/stdc++.h>

using namespace std;

int main()
{
	int w, d;
	while(scanf("%d %d", &w, &d) == 2 && (w || d)) {
		int row[w], col[d];
		map<int, int> cnt;
		int ans = 0;
		for(int i = 0; i < w; i++) {
			scanf("%d", &row[i]);
			cnt[row[i]]++;
			ans += row[i];
		}
		for(int i = 0; i < d; i++) {
			scanf("%d", &col[i]);
			if(cnt[col[i]] == 0)
				ans += col[i];
			else
				cnt[col[i]]--;
		}
		printf("%d\n", ans);
	}


	return 0;
}
