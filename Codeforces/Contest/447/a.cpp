#include <bits/stdc++.h>

using namespace std;

int main()
{
	char inp[1000];
	scanf("%s", inp);
	
	int len = strlen(inp);
	int ans = 0;
	for(int i = 0; i < len; i++) {
		if(inp[i] != 'Q')
			continue;
		for(int j = i + 1; j < len; j++) {
			if(inp[j] != 'Q')
				continue;

			for(int k = i + 1; k < j; k++) {
				if(inp[k] == 'A')
					ans++;
			}
		}
	}
	printf("%d\n", ans);

	return 0;
}
