#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	int inp[n];
	for(int i = 0; i < n; i++)
		scanf("%d", &inp[i]);
	
	if(n == 1) {
		if(inp[0] != 15 && inp[0] != 0)
			printf("-1\n");
		else
			printf("%s\n", inp[0] == 15 ? "DOWN" : "UP"); 
	} else {
		if(inp[n - 1] != 15 && inp[n - 1] != 0) {
			printf("%s\n", inp[n - 1] - inp[n - 2] > 0 ? "UP" : "DOWN");
		} else {
			printf("%s\n", inp[n - 1] == 15 ? "DOWN" : "UP"); 
		}
	}

	return 0;
}
