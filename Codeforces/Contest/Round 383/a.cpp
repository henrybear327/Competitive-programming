#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	if(n == 0) {
		printf("1\n");
		return 0;
	}
	
	n--;
	n %= 4;
	if(n == 0)
		printf("8\n");
	else if(n == 1)
		printf("4\n");
	else if(n == 2)
		printf("2\n");
	else
		printf("6\n");
	
	return 0;
}
