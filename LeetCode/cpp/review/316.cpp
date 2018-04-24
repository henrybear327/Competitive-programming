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
	string removeDuplicateLetters(string s)
	{
		unordered_map<char, int> cnt, in;
		for (auto i : s)
			cnt[i]++;

		stack<char> st;
		for (auto i : s) {
			// WA: condition in[i] == 0
			// since during previous insertion, you have cleared all > chars
			// there is no need to clear again
			while (in[i] == 0 && st.size() > 0 && cnt[st.top()] > 0 && st.top() > i) {
				in[st.top()] = 0;
				st.pop();
			}
			if (in[i] == 0) {
				st.push(i);
				in[i] = 1;
			}
			cnt[i]--;
		}

		string ans = "";
		while (st.size() > 0) {
			ans += st.top();
			st.pop();
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};

#ifdef LOCAL
int main()
{
	return 0;
}
#endif