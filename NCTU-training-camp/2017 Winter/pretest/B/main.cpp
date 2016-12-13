#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	char inp[n + 10];
	scanf("%s", inp);
	
	char prev = inp[0];
	int res = 0;
	for(int i = 1; i < n; i++) {
		if(prev == inp[i])
			res++;
		else
			prev = inp[i];
	}
	printf("%d\n", res);

	return 0;
}
