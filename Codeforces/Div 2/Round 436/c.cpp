#include <bits/stdc++.h>

using namespace std;

void err()
{
	printf("-1\n");
	exit(0);
}	

int main()
{
	int a, b, f, k;
	scanf("%d %d %d %d", &a, &b, &f, &k);
	
	/*
	int left = f * 2;
	int right = (a - f) * 2;
	if(b < left || b < right)
		err();
	*/

	int cap = b;
	int ans = 0;
	if(cap - f < 0)
		err();
	
	for(int i = 0; i < k; i++) {	
		if(i & 1) {
			cap -= a - f;
			if(cap < 0) 
				err();

			cap -= f;
			int offset = (i == k - 1 ? 0 : f);
			if(cap < 0 || cap - offset < 0) {
				cap = b - f;
				ans++;
			}
		} else {
			cap -= f;
			if(cap < 0)
				err();
			
			cap -= a - f;
			int offset = (i == k - 1 ? 0 : a - f);
			if(cap < 0 || cap - offset < 0) {
				cap = b - (a - f);
				ans++;
			}
		}
	}

	printf("%d\n", cap < 0 ? -1 : ans);

	return 0;
}
