// clang-format -style=LLVM -i *.cpp && astyle --style=linux *.cpp && rm *.orig
// && g++ -Wall -Wextra -std=c++11 ...
#include <bits/stdc++.h>
using namespace std;

static int initialSetup = []()
{
    // toggle off cout & cin, instead, use printf & scanf
    std::ios::sync_with_stdio(false);
    // untie cin & cout
    cin.tie(NULL);
    return 0;
}
();

struct Data {
    string s;
    int rep;

    Data(string _s, int _rep)
    {
        s = _s;
        rep = _rep;
    }
};

class Solution
{
public:
    string decodeString(string s)
    {
        stack<Data> st;

        string tmp = "";
        int rep = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            // printf("%d\n", i);

            if (s[i] == '[') {
                st.push(Data("", rep));
                rep = 0;
                continue;
            } else if (s[i] == ']') {
                if (tmp.size() > 0) {
                    st.push(Data(tmp, -1));
                    tmp = "";
                }

                Data d("", -1);
                string concat = "";
                while (1) {
                    d = st.top();
                    st.pop();
                    // printf("%s %d\n", d.s.c_str(), d.rep);

                    if (d.rep != -1)
                        break;
                    concat = d.s + concat;
                }

                string ntmp = "";
                for (int j = 0; j < d.rep; j++)
                    ntmp += tmp.size() > 0 ? tmp : concat;

                st.push(Data(ntmp, -1));
            } else if ('0' <= s[i] && s[i] <= '9') {
                if (tmp.size() > 0) {
                    st.push(Data(tmp, -1));
                    tmp = "";
                }

                rep *= 10;
                rep += s[i] - '0';
            } else { // letters
                tmp += s[i];
            }
        }

        if (tmp.size() > 0)
            st.push(Data(tmp, -1));

        string ans = "";
        while (st.size() > 0) {
            Data d = st.top();
            st.pop();

            ans = d.s + ans;
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    cout << sol.decodeString("2[abc]3[cd]ef") << endl;
    return 0;
}