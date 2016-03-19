#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    pair< string, vector<string> > op[6];
    for(int i = 0; i < k; i++) {
	string s1, s2;
	cin >> s1 >> s2;

	op[s2[0] - 'a'].second.push_back(s1);
    }

    string str = "a";
    queue<string> q;
    q.push(str);
    set<string> ans;

    while(!q.empty()) {
	string cur = q.front();
	q.pop();
	if((int)cur.length() == n) {
	    ans.insert(cur);
	    continue;
	}

	for(int j = 0; j < (int)op[cur[0] - 'a'].second.size(); j++) {
	    string tmp = cur;
	    tmp.insert(0, op[cur[0] - 'a'].second[j]);
	    tmp.erase(0 + 2, 1);

	    q.push(tmp);
	}
    }
    printf("%d\n", (int)ans.size());

    return 0;
}
