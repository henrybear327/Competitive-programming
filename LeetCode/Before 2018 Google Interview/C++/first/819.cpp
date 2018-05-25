#ifdef LOCAL
#include <bits/stdc++.h>
using namespace std;

// tree node stuff here...
#endif

static int __initialSetup = []()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	return 0;
}
();

// handle special cases first
// [], "", ...
// range of input?
class Solution
{
public:
	string mostCommonWord(string paragraph, vector<string> &banned)
	{
		stringstream ss;
		ss.str(paragraph);

		string token;
		unordered_map<string, int> cnt;
		unordered_set<string> ban;
		for (auto i : banned)
			ban.insert(i);
		while (getline(ss, token, ' ')) {
			if (token != "") {
				char *replica = (char *)malloc(sizeof(char) * (token.length() + 2));
				strcpy(replica, token.c_str());
				char *str = strtok(replica, "!?',;. ");
				while (str != NULL) {
					if (strlen(str) > 0) {
						// cout << str << endl;
						int len = strlen(str);
						for (int i = 0; i < len; i++)
							str[i] = tolower(str[i]);
						if (ban.count(str) == 0) {
							cnt[str]++;
						}
					}
					str = strtok(NULL, "!?',;. ");
				}
			}
		}

		int mx = 0;
		string ans;
		for (auto i : cnt) {
			if (i.second > mx) {
				mx = i.second;
				ans = i.first;
			}
		}

		return ans;
	}
};

#ifdef LOCAL
int main()
{
	return 0;
}
#endif