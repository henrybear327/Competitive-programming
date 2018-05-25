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
class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        vector<int> tmp;
        for(int i = 0; i < (int)max(num1.size(), num2.size()); i++) {
            int v1 = 0, v2 = 0;
            if(i < (int)num1.size()) {
                v1 = num1[i] - '0';
            }
            if(i < (int)num2.size()) {
                v2 = num2[i] - '0';
            }

            tmp.push_back(v1 + v2);
        }

        for(int i = 0; i < (int)tmp.size(); i++) {
            if(tmp[i] > 9) {
                if(i == (int)tmp.size() - 1)
                    tmp.push_back(0);
                tmp[i + 1]++;
                tmp[i] %= 10;
            }
            ans += to_string(tmp[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif