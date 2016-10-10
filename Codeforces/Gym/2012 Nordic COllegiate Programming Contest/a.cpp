#include <bits/stdc++.h>

using namespace std;

int main()
{	
	char inp[10000];
	scanf("%s", inp);

	int len = strlen(inp) - 1;
	
	scanf("%s", inp);
	int len1 = strlen(inp) - 1;

	if(len >= len1)
		printf("go\n");
	else
		printf("no\n");

	return 0;
}
