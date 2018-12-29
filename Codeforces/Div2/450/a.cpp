#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		if(a < 0)
			cnt++;
	}		

	printf("%s\n", (cnt <= 1 || (n - cnt) <= 1) ? "Yes" : "No");

	return 0;
}
