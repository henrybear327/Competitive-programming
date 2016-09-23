#include <bits/stdc++.h>

using namespace std;

int main()
{     
	int ncase;
	scanf("%d", &ncase);

	for(int i = 0; i < ncase; i++) {
		int x, y;
		scanf("%d %d", &x, &y);

		if(x == y)
			printf("Square\n");
		else
			printf("Rectangle\n");
	}

	return 0;
}
