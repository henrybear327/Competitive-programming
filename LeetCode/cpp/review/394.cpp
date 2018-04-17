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

struct Data {
    string s;
    int rep;

    Data(string _s)
    {
        s = _s;
        rep = -1;
    }

    Data(int _rep)
    {
        rep = _rep;
        s = "";
    }
};

class Solution
{
private:
    stack<Data> st;

public:
    string decodeString(string s)
    {
        int num = 0;
        string str = "";
        for (auto i : s) {
            if ('0' <= i && i <= '9') { // might end str
                st.push(str);
                str = "";

                num = num * 10 + (i - '0');
            } else {
                if (i == '[') { // proceed with numbers
                    st.push(num);
                    num = 0;
                } else if (i == ']') { // end str
                    st.push(str);
                    str = "";

                    // pop till a number
                    string tmp;
                    while (st.size() > 0) {
                        if (st.top().rep != -1) {
                            string res = "";
                            for (int j = 0; j < st.top().rep; j++)
                                res += tmp;
                            st.pop();
                            st.push(res);
                            break;
                        }
                        tmp = st.top().s + tmp;
                        st.pop();
                    }
                } else { // alphabet
                    str += i;
                }
            }
        }

        string ans = "";
        st.push(str);
        while (st.size() > 0) {
            if (st.top().rep == -1) {
                ans = st.top().s + ans;

            } else {
                string tmp = ans;
                ans = "";
                for (int i = 0; i < st.top().rep; i++) {
                    ans += tmp;
                }
            }

            st.pop();
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