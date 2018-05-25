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

// key observation is written in the comment
// don't be afraid to enumerate!
class Solution
{
private:
    bool isPalindrome(string inp)
    {
        if (inp.length() == 0)
            return true;

        for (int i = 0; i < (int)inp.size() / 2; i++)
            if (inp[i] != inp[(int)inp.size() - 1 - i])
                return false;
        return true;
    }

    void go(vector<string> &words, unordered_map<string, int> &mapping,
            set<pair<int, int>> &s, int i, int j)
    {
        // [0, j) | [j, word_length)
        string lhs = words[i].substr(0, j);
        string rhs = words[i].substr(j, (int)words[i].size());
        if (isPalindrome(lhs)) {
            // ss\sll -> rev rhs | lhs | rhs
            // (lls) | ss | sll (look for lls: rev rhs)
            reverse(rhs.begin(), rhs.end());
            if (mapping.find(rhs) != mapping.end()) {
                if (mapping[rhs] != i)
                    s.insert(make_pair(mapping[rhs], i));
            }
            reverse(rhs.begin(), rhs.end());
        }

        if (isPalindrome(rhs)) {
            // abc\ll -> lhs | rhs | rev lhs
            // abc | ll | (cba) (look for cba: rev lhs)
            reverse(lhs.begin(), lhs.end());
            if (mapping.find(lhs) != mapping.end()) {
                if (mapping[lhs] != i)
                    s.insert(make_pair(i, mapping[lhs]));
            }
            reverse(lhs.begin(), lhs.end());
        }
    }

public:
    vector<vector<int>> palindromePairs(vector<string> &words)
    {
        set<pair<int, int>> s;

        // build string index for searching
        unordered_map<string, int> mapping;
        for (int i = 0; i < (int)words.size(); i++) {
            string ins = words[i];
            mapping[ins] = i;
        }

        for (int i = 0; i < (int)words.size(); i++) {
            if (words[i].length() == 0) {
                for (int j = 0; j < (int)words.size(); j++) {
                    if (isPalindrome(words[j])) {
                        if (j != i) {
                            s.insert(make_pair(j, i));
                            s.insert(make_pair(i, j));
                        }
                    }
                }
            } else {
                for (int j = 0; j < (int)words[i].size(); j++) {
                    go(words, mapping, s, i, j);
                }
            }
        }

        vector<vector<int>> ans;
        for (auto i : s) {
            ans.push_back(vector<int>({i.first, i.second}));
        }
        return ans;
    }
};

// class Solution
// {
// private:
//     bool isPalindrome(string inp)
//     {
//         for (int i = 0; i < (int)inp.size() / 2; i++)
//             if (inp[i] != inp[(int)inp.size() - 1 - i])
//                 return false;
//         return true;
//     }

// public:
//     vector<vector<int>> palindromePairs(vector<string> &words)
//     {
//         vector<vector<int>> ans;
//         if (words.size() == 0)
//             return ans;

//         for (int i = 0; i < (int)words.size(); i++)
//             for (int j = 0; j < (int)words.size(); j++) {
//                 if (i == j)
//                     continue;
//                 if (isPalindrome(words[i] + words[j])) {
//                     vector<int> tmp({i, j});
//                     ans.push_back(tmp);
//                 }
//             }

//         return ans;
//     }
// };

// handle special cases first
// [], "", ...

#ifdef LOCAL
int main()
{
    vector<string> inp({"abcd", "dcba", "lls", "s", "sssll"});
    auto ans = Solution().palindromePairs(inp);
    for (auto i : ans) {
        cout << i[0] << " " << i[1] << endl;
    }
    return 0;
}
#endif