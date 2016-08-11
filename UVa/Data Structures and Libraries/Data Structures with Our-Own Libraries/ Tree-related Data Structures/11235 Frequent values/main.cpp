#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

#define N 100100
struct {
	int data[22][N];

	void build(int inp[], int n) {
		for(int j = 0; j < n; j++) // base case
			data[0][j] = inp[j];
		for(int i = 1; (1 << i) <= n; i++) 
			for(int j = 0; j + (1 << i) <= n; j++) { 
				// printf("%d %d\n", i, j);
				data[i][j] = max(data[i - 1][j], data[i - 1][j + (1 << (i - 1))]);
			}
	}

	int query(int l, int r) { //[l, r)
		int row = log2(r - l);
		return max(data[row][l], data[row][r - (1 << row)]);
	}

	void print(int n) {
		for(int i = 0; i < 3; i++) 
			for(int j = 0; j < n; j++)
				printf("%2d%c", data[i][j], j == n - 1 ? '\n' : ' ');
	}
} sp;
	
int main()
{
	int n;
	while(scanf("%d", &n) == 1 && n) {
		int q;
		scanf("%d", &q);

		int inp[n];
		for(int i = 0; i < n; i++) 
			scanf("%d", &inp[i]);

		// lisan
		map<int, int> cnt;
		for(int i = 0; i < n; i++)
			cnt[inp[i]]++;
		
		int num[cnt.size() + 1], pre[cnt.size() + 1], idx = 1, sum = 0;
		pre[0] = 0;
		num[0] = 0;
		for(auto i : cnt) {
			sum += i.second;
			num[idx] = i.second;
			pre[idx++] = sum;
		}
		
		// build sparse table
		sp.build(num, idx);
		
		/*
		for(int i = 0; i < idx; i++)
			printf("%d%c", pre[i], i == idx - 1 ? '\n' : ' ');
		printf("\n");
		sp.print(idx);
		*/

		for(int i = 0; i < q; i++) {
			int l, r;
			scanf("%d %d", &l, &r);
			
			int lc = (int)(lower_bound(pre, pre + cnt.size() + 1, l) - pre);
			int rc = (int)(lower_bound(pre, pre + cnt.size() + 1, r) - pre);
			// printf("%d %d\n", lc, rc);

			int res = 0;
			// case: same interval
			if(lc == rc) {
				res =  r - l + 1;
			}

			// case: neighboring intervals
			if(rc - lc == 1) {
				res = max(pre[lc] - l + 1, r - pre[rc - 1]);
			}

			// case: > 2 intervals
			if(rc - lc > 1) {
				res = sp.query(lc + 1, rc - 1 + 1);
				res = max(pre[lc] - l + 1, res);
				res = max(r - pre[rc - 1], res);
			}

			printf("%d\n", res);
		}
	}

	return 0;
}
