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
class MagicDictionary
{
private:
	unordered_set<string> has;

public:
	/** Initialize your data structure here. */
	MagicDictionary()
	{
		has.clear();
	}

	/** Build a dictionary through a list of words */
	void buildDict(vector<string> dict)
	{
		for (auto s : dict) {
			has.insert(s);
		}
	}

	/** Returns if there is any word in the trie that equals to the given word
	 * after modifying exactly one character */
	bool search(string word)
	{
		for (uint i = 0; i < word.length(); i++) {
			for (int j = 0; j < 26; j++) {
				if (word[i] - 'a' != j) {
					char orig = word[i];

					word[i] = j + 'a';
					bool ret = has.find(word) != has.end();
					word[i] = orig;

					if (ret)
						return true;
				}
			}
		}

		return false;
	}
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */

#ifdef LOCAL
int main()
{
	return 0;
}
#endif