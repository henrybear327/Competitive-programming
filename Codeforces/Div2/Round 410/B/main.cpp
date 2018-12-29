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
	
	vector<string> possible[50];
	for(int i = 0; i < n; i++) {
		char inp[100];
		scanf("%s", inp);
		string tmp = inp;

		int len = strlen(inp);
		for(int j = 0; j < len; j++) {
			possible[i].push_back(tmp.substr(j, len - j) + tmp.substr(0, j));
			// printf("%s\n", possible[i][j].c_str());
		}
		// printf("\n");
	}
	
	int ans = INT_MAX;
	for(int i = 0; i < n; i++) { // for every head
		bool hasNoSolution = false;
		int tmp = 0;
		for(int j = 0; j < n; j++) { // for every others
			if(i == j)
				continue;

			int ok = -1;
			int len = possible[i][0].length();
			for(int k = 0; k < len; k++) { // check match
				if(possible[i][0] == possible[j][k]) {
					ok = k;
					break;
				}
			}

			if(ok == -1) {
				hasNoSolution = true;
				break;
			} else {
				tmp += ok;
			}	
		}

		if(hasNoSolution == false) {
			ans = min(ans, tmp);
		}
	}

	printf("%d\n", ans == INT_MAX ? -1 : ans);

	return 0;
}
