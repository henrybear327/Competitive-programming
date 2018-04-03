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
    string fractionToDecimal(long long int numerator, long long int denominator)
    {
        // GG
        // what's the range of input?
        string ans = "";
        if ((numerator < 0 && denominator > 0) ||
            (numerator > 0 && denominator < 0))
            ans += "-";
        numerator = llabs(numerator);
        denominator = llabs(denominator);

        ans += to_string(numerator / denominator);

        numerator %= denominator;
        if (numerator != 0) {
            ans += ".";

            string decimal = "";
            // you CAN'T look at quotient!
            // look at remainder!
            // don't be stupid!
            // 1/333
            // 1/332
            unordered_map<int, int> pos; // remainder, pos

            int idx = 0;
            pos[numerator] = idx++; // this is crucial!
            /*
            1/6
            The first position comes from 1/6 r = 1 not 10 / 6 r = 4!!!
            */
            while (numerator != 0) {
                numerator *= 10;
                auto q = numerator / denominator;
                auto r = numerator % denominator;

                decimal += to_string(q);
                if (pos.find(r) == pos.end()) {
                    pos[r] = idx++;
                } else {
                    decimal.insert(pos[r], "(");
                    decimal += ")";
                    break;
                }

                numerator = r;
            }

            ans += decimal;
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