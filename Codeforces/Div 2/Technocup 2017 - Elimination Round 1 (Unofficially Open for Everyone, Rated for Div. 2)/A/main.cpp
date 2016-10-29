#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	
	vector<int> ans;
	while(b > a) {
		ans.push_back(b);
		if(b % 2 == 1) {
			if(b % 10 != 1)
				break;
			b /= 10;
		} else {
			b /= 2;
		}
	}
	if(a == b) {
		ans.push_back(a);
		reverse(ans.begin(), ans.end());
		printf("YES\n");
		printf("%d\n", (int)ans.size());
		for(auto i : ans)
			printf("%d ", i);
	} else {
		printf("NO\n");
	}
	
    return 0;
}
