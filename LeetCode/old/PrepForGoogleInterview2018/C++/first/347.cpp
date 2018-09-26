// clang-format -style=LLVM -i *.cpp && astyle --style=linux *.cpp && rm *.orig
// && g++ -Wall -Wextra -std=c++11 ...
#include <bits/stdc++.h>
using namespace std;

static int initialSetup = []()
{
    // toggle off cout & cin, instead, use printf & scanf
    std::ios::sync_with_stdio(false);
    // untie cin & cout
    cin.tie(NULL);
    return 0;
}
();

typedef pair<int, int> ii;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> acc;
        for (auto i : nums)
            acc[i]++;

        vector<ii> freq;
        for (auto i : acc)
            freq.push_back(ii(i.second, i.first)); // freq, who

        sort(freq.begin(), freq.end());
        reverse(freq.begin(), freq.end());

        vector<int> res;
        k--;
        for (int i = 0; i <= k; i++) {
            res.push_back(freq[i].second);
        }

        return res;
    }
};

int main()
{
    return 0;
}