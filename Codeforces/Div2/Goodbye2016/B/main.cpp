#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	
	int sum = 0;
	bool error = false;
	for(int i = 0; i < n; i++) {
		int d;
		char dir[100];
		scanf("%d %s", &d, dir);
		
		char c = dir[0];
		if(c == 'N') {
			if(sum - d < 0)
				error = true;
			sum -= d;
		} else if(c == 'S') {
			if(sum + d > 20000)
				error = true;
			sum += d;
		} else {
			if(sum == 0 || sum == 20000) {
				error = true;
			}
		}
	}

	if(error == false && sum == 0)
		printf("YES\n");
	else 
		printf("NO\n");

	return 0;
}
