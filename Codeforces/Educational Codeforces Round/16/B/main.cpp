#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
	int n;
	scanf("%d", &n);
	
	int inp[n];
	for(int i = 0; i < n; i++)
		scanf("%d", &inp[i]);
	sort(inp, inp + n);

	if(n % 2 == 0)
		printf("%d\n", inp[(n - 1) / 2]);
	else
		printf("%d\n", inp[n / 2]);

	return 0;
}
