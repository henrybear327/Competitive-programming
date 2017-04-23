#include <bits/stdc++.h>

using namespace std;

int main()
{
	char inp[100];
	scanf("%s", inp);

	int len = strlen(inp);
	
	int mismatch = 0;
	for(int i = 0; i < len / 2; i++) {
		if(inp[i] != inp[len - i - 1])
			mismatch++;
	}
	if(mismatch == 1)
		printf("YES\n");
	else {
		if(mismatch == 0 && len % 2 == 1)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}
