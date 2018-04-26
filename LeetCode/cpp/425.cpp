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

/*
["abat","baba","atan","atal"] -> allow duplication
*/
// class Solution
// {
// private:
//     void dfs(vector<vector<string>> &ans, vector<string> &words,
//              vector<string> &tmp)
//     {
//         // check col, so much optimization here
//         {
//             int i = tmp.size() - 1;
//             for (int j = 0; j < (int)tmp.size(); j++) {
//                 if (tmp[i][j] != tmp[j][i])
//                     return;
//             }
//         }

//         if (tmp.size() == words[0].length()) {
//             ans.push_back(tmp);
//             return;
//         }

//         char startingChar;
//         if (tmp.size() == 0)
//             startingChar = '\0';
//         else
//             startingChar = tmp[0][tmp.size()];

//         for (int i = 0; i < (int)words.size(); i++) {
//             if (startingChar == '\0' || startingChar == words[i][0]) {
//                 tmp.push_back(words[i]);
//                 dfs(ans, words, tmp);
//                 tmp.pop_back();
//             }
//         }
//     }

// public:
//     vector<vector<string>> wordSquares(vector<string> &words)
//     {
//         vector<vector<string>> ans;
//         vector<string> tmp;
//         dfs(ans, words, tmp);
//         return ans;
//     }
// };

class Solution
{
    struct TrieNode {
        // prefix is to keep indexes of all words that have the prefix from root to
        // current node
        vector<int> prefix;
        TrieNode *childs[26];
        TrieNode()
        {
            memset(childs, 0, sizeof(childs));
        }
    };

public:
    vector<vector<string>> wordSquares(vector<string> &words)
    {
        int n = words[0].size();
        TrieNode *root = build(words);
        vector<vector<string>> ans;
        vector<string> board(n);
        for (int i = 0; i < words.size(); i++) {
            board[0] = words[i];
            helper(ans, board, words, root, 1);
        }
        return ans;
    }

private:
    TrieNode *build(vector<string> &words)
    {
        TrieNode *root = new TrieNode();
        for (int i = 0; i < words.size(); i++) {
            TrieNode *p = root;
            for (int j = 0; j < words[i].size() - 1; j++) {
                if (p->childs[words[i][j] - 'a'] == NULL) {
                    p->childs[words[i][j] - 'a'] = new TrieNode();
                }
                p = p->childs[words[i][j] - 'a'];
                p->prefix.push_back(i);
            }
        }
        return root;
    }
    void helper(vector<vector<string>> &ans, vector<string> &board,
                vector<string> &words, TrieNode *root, int row)
    {
        if (row == board.size()) {
            ans.push_back(board);
            return;
        }
        TrieNode *p = root;
        for (int i = 0; i < row; i++) {
            if (p->childs[board[i][row] - 'a'] == NULL)
                return;
            p = p->childs[board[i][row] - 'a'];
        }
        // try every valid word, backtracking
        for (int i : p->prefix) {
            board[row] = words[i];
            helper(ans, board, words, root, row + 1);
        }
    }
};

#ifdef LOCAL
int main()
{
    vector<string> inp{"area", "lead", "wall", "lady", "ball"};
    auto ret = Solution().wordSquares(inp);
    return 0;
}
#endif