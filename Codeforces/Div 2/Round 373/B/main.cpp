#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	char inp[100100];
	scanf("%s", inp);

	// rbbrr
	// rbrbr
	char cur = 'r';
	int r = 0, b = 0;
	for(int i = 0; i < n; i++) {
		if(inp[i] != cur) {
			if(cur == 'r')
				r++;
			else
				b++;
		}
		cur = cur == 'r' ? 'b' : 'r';
	}

	int ans = max(r, b);

	cur = 'b';
	r = 0, b = 0;
	for(int i = 0; i < n; i++) {
		if(inp[i] != cur) {
			if(cur == 'r')
				r++;
			else
				b++;
		}
		cur = cur == 'r' ? 'b' : 'r';
	}

	ans = min(ans, max(r, b));

	printf("%d\n", ans);

	return 0;
}
