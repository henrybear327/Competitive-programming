#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;

#define N 50100
int diff[N];
int inp[N];

int l, n, m;
int check(int mid)
{
	int cnt = 0, prev = 0;
	for(int i = 1; i < n + 1; i++) {
		if(inp[i] - inp[prev] < mid) {
			cnt++;
		} else {
			prev = i;
		}
	}		
	
	if(inp[n + 1] - inp[prev] < mid) 
		cnt++;

	return cnt;
}

int main()
{
	while(scanf("%d %d %d", &l, &n, &m) == 3) {
		inp[0] = 0;
		for(int i = 1; i <= n; i++)
			scanf("%d", &inp[i]);
		inp[n + 1] = l;
		sort(inp, inp + n + 2);

		for(int i = 1; i < n + 2; i++) 
			diff[i - 1] = inp[i] - inp[i - 1];

		int ll = 0, rr = l + 1;
		while(rr - ll > 1) {
			int mid = ll + (rr - ll) / 2;
			
			if(check(mid) <= m) {
				ll = mid;
			} else
				rr = mid;
		}

		// l
		printf("%d\n", ll);
	}

	return 0;
}
