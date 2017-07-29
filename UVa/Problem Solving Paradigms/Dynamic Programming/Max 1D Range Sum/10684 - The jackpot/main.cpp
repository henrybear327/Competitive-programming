#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	while(scanf("%d", &n) == 1 && n != 0) {
		vector<int> inp;
		for(int i = 0; i < n; i++) {
			int num;
			scanf("%d", &num);
			inp.push_back(num);
		}
		
		int mx = INT_MIN;
		int sum = 0;
		for(int i = 0; i < n; i++) {
			sum += inp[i];
			if(sum < 0)
				sum = 0;
			else
				mx = max(sum, mx);
		}

		if(mx <= 0)
			printf("Losing streak.\n");
		else
			printf("The maximum winning streak is %d.\n", mx);
	}

	return 0;
}
