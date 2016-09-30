#include <cstdio>

using namespace std;

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);

	if(a < b)
		printf("No\n");
	else
		printf("%s\n", a % b == 0 ? "Yes" : "No");
	
	return 0;
}
