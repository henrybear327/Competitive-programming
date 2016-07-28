#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
int main()
{
	ull l, r;
	scanf("%llu %llu", &l, &r);
	
	if(l == r) {
		printf("0\n");
		return 0;
	}

	/*
	1100110
	1100111 <- 0111 These will always be there! (2^n XOR 2^n - 1 is the best value you can get)
	1101000 <- 1000
	1101001
	1101010
	1101011
	1101100
	1101101
	1101110
	1101111
	^^^		can be truncated because the XOR will always be 0
	   ^	l will always be 0 and r will always be 1
	*/
		
	ull diff = l ^ r;
	int leading = 64 - __builtin_clzll(diff); 

	ull ans = (1LL << leading) - 1;

	printf("%llu\n", ans);

	return 0;
}
