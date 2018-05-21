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
    // for every index i, the stack only stores the height < i
    int largestRectangleArea(vector<int> &heights)
    {
        stack<int> st;
        st.push(-1); // push index
        int ans = 0;
        for (int i = 0; i < (int)heights.size(); i++) {
            while (st.size() > 1 && heights[st.top()] >= heights[i]) {
                int h = heights[st.top()];
                st.pop();
                int len = (i - 1) - st.top();
                ans = max(ans, h * len);
            }

            st.push(i);
        }

        // 6 7 1 2 4 5 9 7
        while (st.size() > 1) {
            int h = heights[st.top()];
            st.pop();

            int len = ((int)heights.size() - 1) - st.top();
            ans = max(ans, h * len);
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