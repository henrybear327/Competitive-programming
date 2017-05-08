#include <bits/stdc++.h>

using namespace std;
int main()
{
    int ncase;
    scanf("%d", &ncase);

    for(int i = 1; i <= ncase; i++) {
	int n;
	scanf("%d", &n);
	
	int num[3000] = {0};
	for(int j = 0; j < n * 2 - 1; j++) {
	    for(int k = 0; k < n; k++) {
		int cur;
		scanf("%d", &cur);

		num[cur]++;
	    }
	}
	
	printf("Case #%d: ", i);
	vector<int> ans;
	for(int j = 0; j < 3000; j++) {
	    if(num[j] != 0 && num[j] % 2 != 0)
		ans.push_back(j);
	}
	for(int j = 0; j < n; j++)
	    printf("%d%c", ans[j], j == n - 1 ? '\n' : ' ');
    }

    return 0;
}
