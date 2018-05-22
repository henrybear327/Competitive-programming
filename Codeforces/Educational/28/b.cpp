#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, k, m;
	scanf("%d %d %d", &n, &k, &m);
	
	int inp[k];
	int sum = 0;
	for(int i = 0; i < k; i++) {
		scanf("%d", &inp[i]);
		sum += inp[i];
	}
		
	int ans = 0;
	int om = m;
	for(int i = 0; i <= n; i++) {
		m = om;
		priority_queue<int, vector<int>, greater<int>> pq;

		for(int j = 0; j < n - i; j++) {
			for(int x = 0; x < k; x++) {
				// printf("inp[x] = %d\n", inp[x]); 
				pq.push(inp[x]);
			}
		}

		int tmp = 0;
		if(m >= sum * i) {
			tmp += i * (k + 1);
			m -= sum * i;
		}
		
		while(m > 0 && pq.empty() == false) {
			int cur = pq.top();
			pq.pop();
			
			if(m - cur < 0) 
				break;
			tmp++;
			m -= cur;
		}
		
		ans = max(ans, tmp);
	}

	printf("%d\n", ans);

	return 0;
}
