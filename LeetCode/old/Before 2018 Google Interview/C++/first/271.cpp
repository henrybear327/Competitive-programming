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
class Codec
{
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string> &strs)
    {
        string ans;
        for (auto i : strs)
            ans += to_string(i.length()) + ":" + i;
        return ans;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string str)
    {
        vector<string> ans;
        for (int i = 0; i < (int)str.length(); i++) {
            int s = i, e = -1;
            for (int j = s; j < (int)str.length(); j++) {
                if (str[j] == ':') {
                    e = j;
                    break;
                }
            }

            // cout << "substr: " << str.substr(s, e - s) << endl;
            int len = stoi(str.substr(s, e - s));
            ans.push_back(str.substr(e + 1, len));
            i = e + len;
        }
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));

#ifdef LOCAL
int main()
{
    Codec codec;
    vector<string> inp{"abc", "abcd"};
    codec.decode(codec.encode(inp));
    return 0;
}
#endif
