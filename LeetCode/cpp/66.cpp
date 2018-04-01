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
    vector<int> plusOne(vector<int> &digits)
    {
        reverse(digits.begin(), digits.end());

        digits[0]++;
        for (int i = 0; i < (int)digits.size() - 1; i++) {
            digits[i + 1] += digits[i] / 10;
            digits[i] %= 10;
        }

        if (digits[(int)digits.size() - 1] > 9) {
            digits[(int)digits.size() - 1] %= 10;
            digits.push_back(1);
        }

        reverse(digits.begin(), digits.end());

        return digits;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif