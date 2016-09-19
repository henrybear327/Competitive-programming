#include <bits/stdc++.h>

using namespace std;

int main()
{
	char inp[1001000];
	scanf("%s", inp);

	int len = strlen(inp);

	// z algorithm
	int z[len];
	z[0] = 0; // initial 

	int l = 0, r = 0; // z box bound [l, r] 
	for(int i = 1; i < len; i++) {
		if(i > r) { // i not in z box
			l = r = i; // z box contains itself only
			while(r < len && inp[r - l] == inp[r])
				r++;
			z[i] = r - l;
			r--;
		} else { // i in z box
			if(z[i - l] + i <= r)
				z[i] = z[i - l];
			else {
				l = i;
				while(r < len && inp[r - l] == inp[r])
					r++;
				z[i] = r - l;
				r--;
			}
		}
	}
	
	/*
	for(int i = 0; i < len; i++)
		printf("%d %d\n", i, z[i]);
	*/

	int ans = 0;
	for(int i = 1; i < len; i++) {
		if(z[i] + i == len && ans >= z[i]) {
			ans = z[i];
			for(int j = 0; j < ans; j++) 
				printf("%c", inp[j]);
			return 0;
		}

		ans = max(z[i], ans);
	}

	printf("Just a legend\n");


	return 0;
}
