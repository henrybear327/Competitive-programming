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

// D&C solution
// since the max area = min height * width
// so we can use min height as pivit, and recurse
// notice that RMQ can be done by segment tree / sparse table
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        if (n == 0)
            return 0;
        stack<int> s;
        s.push(-1);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int curr = heights[i];
            while (s.top() != -1 && heights[s.top()] > curr) {
                int h = heights[s.top()];
                s.pop();
                // area of s.top() ---> i
                // the key is to take the height from stack top
                // but the index from stack second to top
                // since we are attempting to get (leftmost, i), not [leftmost, i)
                ans = max(ans, h * (i - 1 - s.top()));
            }
            s.push(i);
            // printf("%d %d\n", i, ans);
        }

        while (s.top() != -1) {
            int h = heights[s.top()];
            s.pop();
            ans = max(ans, h * (n - 1 - s.top()));
        }

        return ans;
    }
};

#ifdef LOCAL
int main()
{
    {
        vector<int> inp({2, 1, 5, 6, 2, 3});
        cout << Solution().largestRectangleArea(inp) << endl;
    }
    {
        vector<int> inp({6, 7, 5, 2, 4, 5, 9, 5, 2});
        cout << Solution().largestRectangleArea(inp) << endl;
    }
    {
        vector<int> inp({0, 1, 0, 1});
        cout << Solution().largestRectangleArea(inp) << endl;
    }
    {
        vector<int> inp({2});
        cout << Solution().largestRectangleArea(inp) << endl;
    }
    return 0;
}
#endif