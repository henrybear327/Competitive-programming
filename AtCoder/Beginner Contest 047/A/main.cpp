#include <bits/stdc++.h>

using namespace std;

int main()
{
	int inp[3];
	for(int i = 0; i < 3; i++)
		scanf("%d", &inp[i]);
	
	bool ok = false;
	if(inp[0] + inp[2] == inp[1])
		ok = true;
	if(inp[0] + inp[1] == inp[2])
		ok = true;
	if(inp[1] + inp[2] == inp[0])
		ok = true;
	
	printf("%s\n", ok ? "Yes" : "No");
	
	return 0;
}
