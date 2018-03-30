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

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool cmp(const Interval &a, const Interval &b)
{
    return a.start < b.start;
}

class Solution
{
public:
    vector<Interval> merge(vector<Interval> &intervals)
    {
        // sort(intervals.begin(), intervals.end(), cmp);
        sort(intervals.begin(), intervals.end(),
        [](const Interval &a, const Interval &b) -> bool {
            return a.start < b.start;
        });

        vector<Interval> ans;
        if (intervals.size() == 0)
            return ans;

        int l = intervals[0].start, r = intervals[0].end;
        for (int i = 1; i < (int)intervals.size(); i++) {
            if (r < intervals[i].start) {
                ans.push_back(Interval(l, r));
                l = intervals[i].start;
                r = intervals[i].end;
            } else {
                r = max(r, intervals[i].end);
            }
        }
        ans.push_back(Interval(l, r));

        return ans;
    }
};

int main()
{
    return 0;
}