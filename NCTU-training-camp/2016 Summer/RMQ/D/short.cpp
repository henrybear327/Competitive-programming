#include <bits/stdc++.h>

using namespace std;

int main()
{
		unsigned long long int l, r;
		scanf("%llu %llu", &l, &r);
		printf("%llu\n", l == r ? 0 : (1LL << ((64 - __builtin_clzll(l ^ r)))) - 1);
		
		return 0;
}
