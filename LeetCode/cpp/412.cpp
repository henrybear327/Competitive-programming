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
    vector<string> fizzBuzz(int n)
    {
        vector<string> ans;

        for (int i = 1; i <= n; i++) {
            string tmp = "";
            if (i % 3 == 0 && i % 5 == 0) {
                tmp = "FizzBuzz";
            } else if (i % 3 == 0) {
                tmp = "Fizz";
            } else if (i % 5 == 0) {
                tmp = "Buzz";
            } else {
                tmp = to_string(i);
            }
            ans.push_back(tmp);
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