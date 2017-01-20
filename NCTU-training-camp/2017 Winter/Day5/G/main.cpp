#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int ncase;
	scanf("%d", &ncase);


	while(ncase--) {
		int n;
		scanf("%d", &n);
		int inp[n];
		for(int i = 0; i < n; i++)
			scanf("%d", &inp[i]);

		int q;
		scanf("%d", &q);

		for(int i = 0; i < q; i++) {
			int l, r;
			scanf("%d %d", &l, &r);
			l--;
			r--;
			
			int mx = 0;
			for(int j = l; j <= r; j++) {
				mx = max(mx, inp[j]);
			}

			printf("%d\n", mx);
		}
	}


	return 0;
}
