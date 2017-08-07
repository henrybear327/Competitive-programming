#include <bits/stdc++.h>

using namespace std;

int main()
{
	char inp[1000];
	scanf("%s", inp);
	
	int len = strlen(inp);
	printf("%c%d%c\n", inp[0], len - 2, inp[len - 1]);

	return 0;
}
