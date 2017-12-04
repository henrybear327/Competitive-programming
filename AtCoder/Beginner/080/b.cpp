#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	int sum = 0, tmp = n;
	while(n) {
		sum += n % 10;
		n /= 10;
	}
	n = tmp;

	printf("%s\n", n % sum == 0 ? "Yes" : "No");

	return 0;
}
