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

// observation
// we can sort the people in decreasing order regarding to height,
// tie break by increasing order with regard to ppl in
// then insert (read code)
class Solution
{
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>> &people)
    {
        sort(people.begin(), people.end(),
        [](const pair<int, int> &a, const pair<int, int> &b) -> bool {
            if (a.first == b.first)
                return a.second < b.second;
            return a.first > b.first;
        });

        vector<pair<int, int>> ans;
        for (auto p : people) {
            ans.insert(ans.begin() + p.second, p);
        }

        return ans;
    }
};

int main()
{
    return 0;
}
