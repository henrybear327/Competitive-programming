#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	
	char inp[200010];
	scanf("%s", inp);
	int allin = 0, in = 0, folded = 0;
	for(int i = 0; i < n; i++)
		if(inp[i] == 'A')
			allin++;
		else if(inp[i] == 'I')
			in++;
		else
			folded++;
	
	int ans = 0;
	for(int i = 0; i < n; i++)
		if(inp[i] == 'A' || inp[i] == 'I') {
			if(allin + folded - (inp[i] == 'A' ? 1 : 0) == n - 1)
				ans++;
		}

	printf("%d\n", ans);

	return 0;
}
