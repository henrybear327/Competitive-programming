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

// Trie

struct Node {
    Node **next;

    Node()
    {
        next = (Node **)malloc(26 * sizeof(Node *));
        for (int i = 0; i < 26; i++)
            next[i] = NULL;
    }
};

class Trie
{
private:
    struct Node *head;
    void dfs(Node *cur, int &count, int depth)
    {
        if (cur == NULL)
            return;

        int cnt = 0;
        for (int i = 0; i < 26; i++)
            if (cur->next[i] != NULL) {
                cnt++;
                dfs(cur->next[i], count, depth + 1);
            }
        if (cnt == 0)
            count += depth + 1;
    }

public:
    Trie()
    {
        head = new Node;
    }

    void addString(string inp)
    {
        Node *cur = head;
        for (auto i : inp) {
            int id = i - 'a';
            if (cur->next[id] == NULL) {
                cur->next[id] = new Node;
            }
            cur = cur->next[id];
        }
    }

    int countLeaf()
    {
        int count = 0;
        dfs(head, count, 0);
        return count;
    }
};

class Solution
{
public:
    int minimumLengthEncoding(vector<string> &words)
    {
        Trie trie;
        for (auto i : words) {
            string rev = i;
            reverse(rev.begin(), rev.end());
            trie.addString(rev);
        }

        return trie.countLeaf();
    }
};

// n words
// O(nlogn + n * 7) = O(nlogn)
// class Solution
// {
// public:
//     int minimumLengthEncoding(vector<string> &words)
//     {
//         // sort by length, longest to shortest
//         sort(words.begin(), words.end(),
//         [](const string &a, const string &b) -> bool {
//             return a.length() > b.length();
//         });

//         string ans = "";
//         unordered_set<string> s(words.begin(), words.end());

//         for (int i = 0; i < (int)words.size(); i++) {
//             if (s.count(words[i]) == 0)
//                 continue;

//             s.erase(words[i]);
//             ans += words[i] + "#";

//             for (int j = words[i].length() - 1; j >= 0; j--) {
//                 string query = words[i].substr(j);
//                 if (s.count(query) == 1) {
//                     s.erase(query);
//                 }
//             }
//         }

//         return ans.length();
//     }
// };

#ifdef LOCAL
int main()
{
    return 0;
}
#endif