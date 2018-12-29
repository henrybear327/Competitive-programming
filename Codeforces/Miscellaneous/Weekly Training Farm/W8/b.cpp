#include <cstdio>

using namespace std;

int main()
{
	long long a;
	scanf("%lld", &a);

	printf("%d\n", __builtin_popcountll(a));
	return 0;
}
