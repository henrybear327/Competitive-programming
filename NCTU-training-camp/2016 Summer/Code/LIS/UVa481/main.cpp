#include <bits/stdc++.h>

using namespace std;

int main()
{
    int cur;
    vector<int> inp;
    while(scanf("%d", &cur) == 1) {
	inp.push_back(cur);
    }	
    
    int n = (int)inp.size();
    int val[n], idx[n];
    fill(val, val + n, INT_MAX);
    fill(idx, idx + n, -1);

    int pre[n];
    memset(pre, -1, sizeof(pre));
    int lenCnt = 0;
    for(int i = 0; i < n; i++) {
	int pos = (int) (lower_bound(val, val + n, inp[i]) - val);
	// printf("pos %d\n", pos);
	
	if(val[pos] == INT_MAX) {
	    lenCnt++;
	    idx[pos] = i;
	    val[pos] = inp[i];
	} else if( val[pos] >= inp[i]) {
	    val[pos] = inp[i];
	    idx[pos] = i;
	}

	pre[i] = (pos - 1 < 0 || idx[pos - 1] == -1) ? -1 : idx[pos - 1];
    }
    
    /*
    for(int i = 0; i < n; i++)
	printf("(%d, %d)%c", idx[i], val[i], i == n - 1 ? '\n' : ' ');
    for(int i = 0; i < n; i++)
	printf("%d%c", pre[i], i == n - 1 ? '\n' : ' ');
    */

    vector<int> ans;
    for(int i = idx[lenCnt - 1]; i != -1; i = pre[i])
	ans.push_back(inp[i]);
    reverse(ans.begin(), ans.end());
    
    printf("%d\n-\n", (int)ans.size());
    for(auto i : ans)
	printf("%d\n", i);

    return 0;
}
