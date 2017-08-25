#include <bits/stdc++.h>

using namespace std;

void printString(string ans)
{
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
	reverse(ans.begin(), ans.end());
}

int main()
{
	char inp[200010];
	scanf("%s", inp);
	
	int len = strlen(inp);
	string ans = "a";
	set<char> has;
	for(int i = len - 1; i >= 0; i--) {
		char c = inp[i];
		has.insert(c);
		
		if(ans[ans.length() - 1] != c) {
			continue;
		}

		if(has.size() == 4) {
			has.clear();
			ans += 'a';
		} else {
			for(char j = 'a'; j <= 'd'; j++) {
				if(has.find(j) == has.end()) {
					ans[ans.length() - 1] = j;
					break;
				}
			}
		}
	}
	
	reverse(ans.begin(), ans.end());
	cout << ans << endl;

	return 0;
}
