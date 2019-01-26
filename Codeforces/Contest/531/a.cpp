#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
	int n;
	scanf("%d", &n);

	n %= 4;
	if (n == 1 || n == 2)
		printf("1\n");
	else
		printf("0\n");

	return 0;
}
