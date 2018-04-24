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

// exist greedy solution
class Solution
{
public:
    int maximumSwap(int num)
    {
        int ans = num;

        vector<int> inp;
        while (num > 0) {
            inp.push_back(num % 10);
            num /= 10;
        }
        reverse(inp.begin(), inp.end());

        int lastExistence[10] = {0};
        int n = inp.size();
        for (int i = 0; i < n; i++) {
            lastExistence[inp[i]] = i;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 9; j > inp[i]; j--) {
                if (lastExistence[j] > i) {
                    swap(inp[i], inp[lastExistence[j]]);
                    string tmp;
                    for (auto k : inp)
                        tmp += to_string(k);
                    return stoi(tmp);
                }
            }
        }

        return ans;

        // int n = inp.size();
        // for (int i = 0; i < n; i++) {
        //     for (int j = i + 1; j < n; j++) {
        //         if (inp[i] > inp[j])
        //             continue;
        //         swap(inp[i], inp[j]);
        //         string tmp;
        //         for (auto k : inp)
        //             tmp += to_string(k);

        //         ans = max(ans, stoi(tmp));
        //         swap(inp[i], inp[j]);
        //     }
        // }

        return ans;
    }
};

#ifdef LOCAL
int main()
{
    cout << Solution().maximumSwap(2736) << endl;
    return 0;
}
#endif