#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    vector<int> item;

    for(int i = 0; i < k; i++) {
	int tmp;
	scanf("%d", &tmp);
	item.push_back(tmp);
    }
    item.push_back(-1);
    reverse(item.begin(), item.end());
    
    int ans = 0;
    for(int i = 0; i < n; i++) {
	for(int j = 0; j < m; j++) {
	    int cur;
	    scanf("%d", &cur);

	    for(int l = 1; l <= k; l++) {
		if(cur == item[l]) {
		    ans += k + 1 - l;
		    item.erase(item.begin() + l);
		    item.push_back(cur);
		    break;
		}
	    }
	}
    }

    printf("%d\n", ans);

    return 0;
}
