#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m;
	while(scanf("%d %d", &n, &m) == 2) {
		int f[n], b[m];
		for(int i = 0; i < n; i++)
			scanf("%d", &f[i]);
		for(int i = 0; i < m; i++)
			scanf("%d", &b[i]);

		vector<double> l;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				l.push_back(1.0 * b[j] / f[i]);
		sort(l.begin(), l.end());
		
		double ans = LLONG_MIN;
		for(int i = 1; i < (int)l.size(); i++) {
			ans = max(ans, l[i] / l[i - 1]);
		}
		printf("%.2f\n", ans);
	}
	
	return 0;
}
