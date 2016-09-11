#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n = 3;
	printf("%d\n", n);
	srand(time(NULL));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++)
			printf("%d ", rand() % 100 + 1);
		printf("\n");
	}

	return 0;
}
