#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	
	printf("%s\n", n % 10 == n / 100 ? "Yes" : "No");

	return 0;
}
