#include <bits/stdc++.h>

using namespace std;

int main()
{
    int cur;
    vector<int> inp;
    while(scanf("%d", &cur) == 1) {
	inp.push_back(cur);
    }	

    int lis[inp.size()], pre[inp.size()];
    fill(lis, lis + inp.size(), 1);
    fill(pre, pre + inp.size(), -1);

    for(int i = 1; i < (int)inp.size(); i++) {
	for(int j = 0; j < i; j++) {
	    if(inp[i] > inp[j]) {
		lis[i] = max(lis[i], lis[j] + 1);
		pre[i] = j;
	    }
	}
    }
    
    int max = 0, idx;
    for(int i = 0; i < (int)inp.size(); i++) {
	if(lis[i] >= max) {
	    max = lis[i];
	    idx = i;
	}
    }

    vector<int> ans;
    for(int i = idx; i != -1; i = pre[i]) {
	ans.push_back(inp[i]);
    }
    reverse(ans.begin(), ans.end());

    printf("%d\n-\n", (int)ans.size());
    for(auto i : ans)
	printf("%d\n", i);

    return 0;
}
