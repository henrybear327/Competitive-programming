#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	a = a > 0 ? 1 : 0;
	b = b > 0 ? 1 : 0;
	c = c > 0 ? 1 : 0;
	
	bool ok = false;
	if((a & b) == c) {
		printf("AND\n");
		ok = true;
	}
	if((a | b) == c) {
		printf("OR\n");
		ok = true;
	}
	if((a ^ b) == c) {
		printf("XOR\n");
		ok = true;
	}

	if(!ok)
		printf("IMPOSSIBLE\n");
	
	return 0;
}
