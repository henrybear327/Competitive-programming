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
        stack<int> st; // length so far

        // input = regex_replace(input, regex("    "), "\t");
        // cout << input << endl;

        int ans = 0;

        string tok;
        stringstream ss;
        ss.str(input);

        while (getline(ss, tok, '\n')) {
            // get \t -> nesting level
            int level = -1;
            for (int i = (int)tok.size(); i >= 0; i--) {
                if (tok[i] == '\t') {
                    level = i;
                    break;
                }
            }
            level++; // pos 0 has \t -> 1 \t -> nesting level 1

            while (level < (int)st.size()) {
                // level 1, stack sz = 1 -> containing len of level 0
                st.pop();
            }

            // stack top length + / + (current name - tab count)
            int len = (st.size() > 0 ? st.top() + 1 : 0) + ((int)tok.size() - level);
            if (tok.find(".") != string::npos)
                ans = max(ans, len);
            else
                st.push(len);
        }

        return ans;
    }
};

#ifdef LOCAL
int main()
{
    cout << Solution().lengthLongestPath("dir\n\t    file.txt") << endl;
    cout << Solution().lengthLongestPath("dir\n        file.txt")
         << endl; // a filename as a top-level file WTF

    // cout << Solution().lengthLongestPath(
    //          "dir\n\tsubdir1\n\t\tfile1."
    //          "ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext")
    //      << endl;

    // cout << Solution().lengthLongestPath("a") << endl;
    return 0;
}
#endif