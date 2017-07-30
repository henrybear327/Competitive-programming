#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	
	int inp[n];
	for(int i = 0; i < n; i++) 
		scanf("%d", &inp[i]);
	
	bool ok = true;
	int diff[n - 1];
	for(int i = 1; i < n; i++) {
		int tmp = inp[i] - inp[i - 1];

		if(tmp > 0)
			diff[i - 1] = -1;
		else if(tmp == 0)
			diff[i - 1] = 0;
		else
			diff[i - 1] = 1;
	}
	
	if(n == 2)
		ok = true;
	else {
		for(int i = 1; i < n - 1; i++) {
			if(diff[i - 1] > diff[i])
				ok = false;
		}
	}

	printf("%s\n", ok ? "YES" : "NO");

	return 0;
}
