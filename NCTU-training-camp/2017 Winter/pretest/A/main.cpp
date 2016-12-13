#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	
	int num[n];
	int odd = 0, even = 0;
	for(int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
		if(num[i] % 2 == 0)
			even++;
		else
			odd++;
	}

	for(int i = 0; i < n; i++){
		if(odd == 1 && num[i] % 2 == 1)
			printf("%d\n", i + 1);
		else if(even == 1 && num[i] % 2 == 0)
			printf("%d\n", i + 1);
	}

	return 0;
}
