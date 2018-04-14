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
    unordered_map<string, int> cnt;
    unordered_map<string, string> sample;
    string conv(string i)
    {
        int len = (int)i.length() - 2;
        if (len < 0)
            len = 0;
        return i.front() + to_string(len) + i.back();
    }

public:
    ValidWordAbbr(vector<string> dictionary)
    {
        unordered_set<string> dict;
        for (auto i : dictionary)
            dict.insert(i);
        for (auto i : dict) {
            cnt[conv(i)]++;
            sample[conv(i)] = i;
        }
    }

    bool isUnique(string word)
    {
        if (cnt[conv(word)] == 0) {
            return true;
        } else if (cnt[conv(word)] == 1 &&
                   sample[conv(word)] == word) { // this special condition
            return true;
        }
        return false;
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
