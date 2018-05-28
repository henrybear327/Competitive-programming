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
// ".L.R...LR..L.."
// "LL.RR.LLRRLL.."
class Solution
{
public:
    string pushDominoes(string dominoes)
    {
        char left = 'L';
        int pos = 0;
        string ans = "L" + dominoes + "R";
        dominoes = ans;
        for (int i = 0; i < (int)dominoes.length(); i++) {

            if (dominoes[i] == '.')
                continue;

            if (left == 'L' && dominoes[i] == 'L') {
                for (int j = pos + 1; j < i; j++)
                    ans[j] = 'L';
            } else if (left == 'L' && dominoes[i] == 'R') {
                // do nothing
            } else if (left == 'R' && dominoes[i] == 'L') {
                int diff = i - pos - 1;
                for (int j = pos + 1; j < pos + 1 + diff / 2; j++)
                    ans[j] = 'R';
                for (int j = i - diff / 2; j < i; j++)
                    ans[j] = 'L';
            } else { // R R
                for (int j = pos + 1; j < i; j++)
                    ans[j] = 'R';
            }

            left = dominoes[i];
            pos = i;
        }

        return ans.substr(1, (int)ans.length() - 2);
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif