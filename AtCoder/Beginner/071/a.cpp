#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, a, b;
	scanf("%d %d %d", &n, &a, &b);

	if(abs(n - a) <= abs(n - b))
		printf("A\n");
	else
		printf("B\n");

	return 0;
}
