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

const int N = 500000;

struct Node {
    int left, right;
    void init()
    {
        left = -1;
        right = -1;
    }
};

struct Trie {
    Node nodes[N];
    int nextAvailable;
    void init()
    {
        nodes[0].init();
        nextAvailable = 1;
    }

    vector<int> toBinary(int x)
    {
        vector<int> ans(32, 0);
        for (int i = 0; i < 32; i++)
            ans[i] = (x >> i) & 1;
        reverse(ans.begin(), ans.end()); // so now [0] is MSB
        return ans;
    }

    int toInteger(vector<int> &num)
    {
        reverse(num.begin(), num.end());
        int ans = 0;
        for (int i = 0; i < 32; i++)
            if (num[i] == 1)
                ans |= (1 << i);
        return ans;
    }

    void insert(const vector<int> &num)
    {
        int pos = 0;
        for (int i = 0; i < 32; i++) {
            if (num[i] == 0) {
                if (nodes[pos].left == -1) {
                    nodes[nextAvailable].init();
                    nodes[pos].left = nextAvailable++;
                }
                pos = nodes[pos].left;
            } else {
                if (nodes[pos].right == -1) {
                    nodes[nextAvailable].init();
                    nodes[pos].right = nextAvailable++;
                }
                pos = nodes[pos].right;
            }
        }
    }

    void insert(int x)
    {
        auto num = toBinary(x);
        insert(num);
    }

    vector<int> search(const vector<int> &num)
    {
        vector<int> ans;
        int pos = 0;
        for (int i = 0; i < 32; i++) {
            if (num[i] == 0) {
                if (nodes[pos].right == -1) {
                    ans.push_back(0);
                    pos = nodes[pos].left;
                } else {
                    pos = nodes[pos].right;
                    ans.push_back(1);
                }
            } else {
                if (nodes[pos].left == -1) {
                    ans.push_back(1);
                    pos = nodes[pos].right;
                } else {
                    pos = nodes[pos].left;
                    ans.push_back(0);
                }
            }
        }
        return ans;
    }

    int search(int x)
    {
        // look for the most mismatched number
        auto num = toBinary(x);
        auto res = search(num);
        return toInteger(res);
    }
};

class Solution
{
public:
    int findMaximumXOR(vector<int> &nums)
    {
        // observation
        // let's look at the numbers in their binary representation
        // starting from the MSB (leftmost) bit
        // for every number, we look for the most mismatched number
        // thus we can get the max value of them all
        // trie!

        int mx = 0;
        Trie trie;
        trie.init();
        for (auto i : nums) {
            trie.insert(i);
            mx = max(mx, i ^ trie.search(i));
        }
        return mx;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif