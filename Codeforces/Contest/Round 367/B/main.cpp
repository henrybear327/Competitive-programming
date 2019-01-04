#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int main()
{
	int n;
	scanf("%d", &n);
	
	int inp[n];
	for(int i = 0; i < n; i++)
		scanf("%d", &inp[i]);
	
	int q;
	scanf("%d", &q);
	sort(inp, inp + n);

	for(int i =0; i < q; i++) {
		int x;
		scanf("%d", &x);

		int l = -1, r = n;
		while(r - l > 1) {
			int mid = (l + r) / 2;
			if(inp[mid] > x)
				r = mid;
			else
				l = mid;
		}

		printf("%d\n", l + 1);
	}
	
    return 0;
}
