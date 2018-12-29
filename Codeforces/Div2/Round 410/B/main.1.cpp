#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	if(n == 1) {
		printf("0\n");
		return 0;
	}		
	
	string possible[50];
	for(int i = 0; i < n; i++) {
		char inp[100];
		scanf("%s", inp);
		string tmp = inp;
		tmp += tmp;
		possible[i] = tmp;
	}
	
	int ans = INT_MAX;
	for(int i = 0; i < n; i++) { // for every head
		bool hasNoSolution = false;
		int tmp = 0;
		int len = possible[i].length();
		for(int j = 0; j < n; j++) { // for every others
			if(i == j)
				continue;

			int ok = possible[j].find(possible[i].substr(0, len / 2));
			if(ok >= 0) {
				tmp += ok;
			} else {
				hasNoSolution = true;
				break;
			}
		}

		if(hasNoSolution == false) {
			ans = min(ans, tmp);
		}
	}

	printf("%d\n", ans == INT_MAX ? -1 : ans);

	return 0;
}
