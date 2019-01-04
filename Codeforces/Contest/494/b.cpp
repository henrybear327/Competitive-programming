#include <bits/stdc++.h>

using namespace std;

int main()
{
    int zero, one, x;
    cin >> zero >> one >> x;

    string mix = "", ans;
    if (zero >= one) {
        mix += "0";
        zero--;
        int cur = 1;
        while (x > 0) {
            mix += to_string(cur);
            if (cur == 1)
                one--;
            else
                zero--;
            cur ^= 1;
            x--;
        }

    } else {
        mix += "1";
        one--;
        int cur = 0;
        while (x > 0) {
            mix += to_string(cur);
            if (cur == 1)
                one--;
            else
                zero--;
            cur ^= 1;
            x--;
        }
    }

    string zeroStr, oneStr;
    for (int i = 0; i < zero; i++)
        zeroStr += "0";
    for (int i = 0; i < one; i++)
        oneStr += "1";
    if (mix.back() == mix.front()) {
        if (mix.back() == '0') {
            mix = mix.substr(0, mix.length() - 1) + oneStr + "0";
            oneStr = "";
        } else {
            mix = mix.substr(0, mix.length() - 1) + zeroStr + "1";
            zeroStr = "";
        }
    }
    if (mix.front() == '0') {
        ans = zeroStr + mix + oneStr;
    } else {
        ans = oneStr + mix + zeroStr;
    }

    cerr << mix << endl;
    cout << ans << endl;

    return 0;
}
