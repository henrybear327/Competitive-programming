#include <bits/stdc++.h>
//LLONG_MIN LLONG_MAX INT_MIN INT_MAX

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    vector<pair <int, int> > ans;
    set<int> st;
    int prev = 0;
    for(int i = 0; i < n; i++) {
	int tmp;
	scanf("%d", &tmp);

	if(st.find(tmp) != st.end()) {
	    ans.push_back(make_pair(prev, i));
	    prev = i + 1;
	    st.clear();
	} else {
	    st.insert(tmp);
	}
    }

    if(ans.size() == 0 || prev != n) {
	if(prev != n && ans.size() != 0) {
	    ans[ans.size() - 1].second = n - 1;
	} else {
	    printf("-1\n");
	    return 0;
	}
    } 

    printf("%d\n", (int)ans.size());
    for(int i = 0; i < (int)ans.size(); i++) {
	printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
    }

    return 0;
}
