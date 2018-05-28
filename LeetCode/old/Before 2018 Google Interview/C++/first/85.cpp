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
private:
    int maxRect(vector<int> &heights)
    {
        stack<int> s;
        s.push(-1);

        int ans = 0, n = (int)heights.size();
        for (int i = 0; i < n; i++) {
            // printf("%d %d\n", i, heights[i]);
            while (s.top() != -1 && heights[s.top()] > heights[i]) {
                int h = heights[s.top()];
                s.pop();
                ans = max(ans, h * (i - 1 - s.top()));
            }
            s.push(i);
        }

        while (s.top() != -1) {
            int h = heights[s.top()];
            s.pop();
            ans = max(ans, h * (n - 1 - s.top()));
        }
        return ans;
    }

public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int n = matrix.size();
        if (n == 0)
            return 0;
        int m = matrix[0].size();
        vector<int> heights(m, 0);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '0')
                    heights[j] = 0;
                else
                    heights[j]++;
            }

            // printf("%d %d\n", i, maxRect(heights));
            ans = max(ans, maxRect(heights));
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