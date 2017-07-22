// build a table that contains all possible sums
// binary search for the answer

// WTF
// using set 1.2s
// using array 0.06s

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	int ncase = 1;
	while(scanf("%d", &n) == 1 && n) {
		int inp[n];
		for(int i = 0; i < n; i++)
			scanf("%d", &inp[i]);
		
		int sz = n * (n - 1) / 2;
		int sum[sz], idx = 0;
		for(int i = 0; i < n; i++)
			for(int j = i + 1; j < n; j++)
				sum[idx++] = inp[i] + inp[j];
		sort(sum, sum + sz);
		/*
		set<int> sum;
		for(int i = 0; i < n; i++) 
			for(int j = i + 1; j < n; j++)
				sum.insert(inp[i] + inp[j]);
		*/

		int m;
		scanf("%d", &m);
		printf("Case %d:\n", ncase++);

		for(int i = 0; i < m; i++) {
			int q;
			scanf("%d", &q);
			
			auto lb = lower_bound(sum, sum + sz, q);
			int diff = *lb;
			
			if(lb != sum) {
				lb--;
				if(abs(*lb - q) < abs(diff - q))
					diff = *lb;
			}
			/*
			auto lb = sum.lower_bound(q);
			
			int diff = *lb;
			if(distance(sum.begin(), lb) >= 2) { // distance(first, last)
				lb--;

				if(abs(*lb - q) < abs(diff - q))
					diff = *lb;
			}
			*/
			printf("Closest sum to %d is %d.\n", q, diff);
		}
	}

	return 0;
}
