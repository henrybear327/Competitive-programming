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

class Solution
{
public:
    int lengthLongestPath(string input)
    {
        stack<int> st;
        st.push(0); // "dummy" length
        int maxLen = 0;

        // input = regex_replace(input, regex("    "), "\t");
        // cout << input << endl;

        string s;
        stringstream ss;
        ss.str(input);

        while (getline(ss, s, '\n')) {
            int last_tab = -1;
            for (int i = s.length() - 1; i >= 0; i--)
                if (s[i] == '\t') {
                    last_tab = i;
                    break;
                }

            int lev = last_tab + 1;          // number of "\t"
            while (lev + 1 < (int)st.size()) // find parent
                st.pop();
            int len = st.top() + s.length() - lev + 1; // remove "\t", add"/"
            st.push(len);
            // check if it is file
            if (s.find(".") != string::npos)
                maxLen = max(maxLen, len - 1);
        }
        return maxLen;
    }
};

#ifdef LOCAL
int main()
{
    cout << Solution().lengthLongestPath("dir\n\t    file.txt") << endl; // a filename starts with 4 spaces WTF?
    cout << Solution().lengthLongestPath("dir\n        file.txt") << endl;

    // cout << Solution().lengthLongestPath(
    //          "dir\n\tsubdir1\n\t\tfile1."
    //          "ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext")
    //      << endl;

    // cout << Solution().lengthLongestPath("a") << endl;
    return 0;
}
#endif