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

/*
Testcases:
""
"1"
"-1"
"        1"
" -1"
"?1"
"  10101019"
"       -103982938"
"       9999999999999999999"
"       -999999999999999999"
"+1"
"   1    "
"  1  0* "
*/
class Solution
{
public:
    int myAtoi(string str)
    {
        bool started = false;
        long long int x = 0;
        bool isNeg = false;
        for (auto i : str) {
            if (started) {
                if ('0' <= i && i <= '9') {
                    x *= 10;
                    x += i - '0';
                } else {
                    break;
                }
            } else {
                if (i == ' ')
                    continue;

                if (i == '-') {
                    isNeg = true;
                    started = true;
                } else if (i == '+') {
                    started = true;
                } else if ('0' <= i && i <= '9') {
                    x += i - '0';
                    started = true;
                } else {    // random bullshit
                    return 0; // can't convert
                }
            }

            if (isNeg == false && x > INT_MAX) {
                return INT_MAX;
            } else if (isNeg == true && x > INT_MAX) {
                return INT_MIN;
            }
        }

        return isNeg ? -x : x;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif