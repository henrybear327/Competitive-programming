#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	a %= b;

	// 1 / 2
	// 1 / 1000

	for(int i = 1; i <= 1000000; i++) {
		a *= 10;
		int q = a / b;
		int rem = a % b;

		if(q == c) {
			printf("%d\n", i);
			return 0;
		}

		a = rem;
	}

	printf("-1\n");

	return 0;
}
