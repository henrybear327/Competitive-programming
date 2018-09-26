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
class ValidWordAbbr
{
private:
	inline string abbr(string& inp)
	{
		int len = inp.length();
		if (len <= 2)
			len = 0;

		return inp.front() + (len != 0 ? to_string(len) : "") + inp.back();
	}
	unordered_map<string, pair<int, string>> cnt;

public:
	ValidWordAbbr(vector<string> dictionary)
	{
		// dictionary has duplicate
		unordered_set<string> duplicate;
		for (auto i : dictionary) {
			if (duplicate.count(i) > 0)
				continue;
			duplicate.insert(i);

			auto ret = cnt[abbr(i)];
			ret.first++;
			ret.second = i;
			cnt[abbr(i)] = ret;
		}
	}

	bool isUnique(string word)
	{
		// if same i18n is found and it only have one
		// your need to check if the query word = that i18n word!

		if (cnt.count(abbr(word)) > 0) {
			if (cnt[abbr(word)].first == 1 && cnt[abbr(word)].second == word)
				return true;
			return false;
		}
		return true;
	}
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj.isUnique(word);
 */

#ifdef LOCAL
int main()
{
	return 0;
}
#endif