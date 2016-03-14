#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    unordered_map<string, int> cnt;
    int n, m;
    cin >> n >> m;  
    bool ok = false;

    for(int i = 0; i < n; i++) {
	string tmp;
	cin >> tmp;
	
	int ones = 0;
	for(int j = 0; j < m; j++)
	    if(tmp[j] == '1')
		ones++;

	if(8 <= ones && ones <= 15) {
	    cnt[tmp]++;
	    ok = true;
	}
    }

    string ans;
    if(ok == false) {
	ans.clear();
	ans += "11111111";
	for(int i = 0; i < m - 8; i++)
	    ans.append("0");
    }
    
    int mx = INT_MIN;
    for(auto i : cnt) {
	if(i.second > mx) {
	    mx = i.second;
	    ans.clear();
	    ans = i.first;
	}
    }
    
    cout << ans << endl;	



    return 0;
}
