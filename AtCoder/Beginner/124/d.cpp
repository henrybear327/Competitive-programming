#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	
	char inp[n + 3];
	scanf("%s", inp);
	int num[n];
	for(int i = 0; i < n; i++) {
		num[i] = inp[i] == '0' ? 0 : 1;
	}
	
	int l = 0;
	int sum = 0, ans = 0;
	int i = 0;
	// 111000111
	// 000111000
	// 000111
	// 111000
	while(i < n) {
		while(i < n && num[i] == 1)
			i++;
		ans = max(ans, i - l);
		while(i < n && num[i] == 0)
			i++;
		k--;
		if(k < 0) {
			while(l < n && num[l] == 1)
				l++;
			while(l < n && num[l] == 0)
				l++;
		}

		ans = max(ans, i - l);
	}

	printf("%d\n", ans);

	return 0;
}
