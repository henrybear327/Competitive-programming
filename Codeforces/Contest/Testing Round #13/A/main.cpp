#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	
	vector<int> ans;
	for(int i = 1; i <= 1000; i++) {
		if(n - i < 0) {
			ans.back() += n;
			n = 0;
		} else {
			ans.push_back(i);
			n -= i;
		}

		if(n == 0)
			break;
	}
	
	printf("%d\n", (int)ans.size());
	for(auto i : ans)
		printf("%d ", i);
	
	return 0;
}
