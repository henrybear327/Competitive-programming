#include <bits/stdc++.h>

using namespace std;

int main()
{
	int ncase;
	scanf("%d", &ncase);
	
	int cnt = 1;
	while(ncase--) {
		int n;
		scanf("%d", &n);
		
		int a[n], b[n];
		for(int i = 0; i < n; i++) {
			int num;
			scanf("%d", &num);
			
			b[i] = num >> 16;
			a[i] = num ^ (b[i] << 16);
		}
		
		printf("Case %d:\n", cnt++);
		for(int i = 0; i < n; i++) 
			printf("%d%c", a[i], i == n - 1 ? '\n' : ' ');
		for(int i = 0; i < n; i++) 
			printf("%d%c", b[i], i == n - 1 ? '\n' : ' ');
	}

	return 0;
}
