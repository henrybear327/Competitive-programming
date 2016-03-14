#include <bits/stdc++.h>
//LLONG_MIN LLONG_MAX INT_MIN INT_MAX

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    vector<int> ans;
    for(int i = 0; i < n; i++) {
	ans.push_back(1);
	while (ans.size() >= 2) {
	    int last = ans.size() - 1;
	    if (ans[last] == ans[last - 1]) {
		int tmp = ans[last];
		tmp++;
		ans.pop_back();
		ans.pop_back();
		ans.push_back(tmp);
	    } else
		break;
	}
    }

    for(int i = 0; i < (int)ans.size(); i++)
	printf("%d%c", ans[i], i == (int)ans.size() - 1 ? '\n' : ' ');

    return 0;
}
