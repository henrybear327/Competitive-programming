// :%s/^ \* //g
#ifdef LOCAL
#include <bits/stdc++.h>
using namespace std;

// define data structures here
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
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
    vector<Interval> merge(vector<Interval> &intervals)
    {
        sort(intervals.begin(), intervals.end(),
        [](const Interval &a, const Interval &b) -> bool {
            return a.start < b.start;
        });

        vector<Interval> ans;
        if (intervals.size() == 0)
            return ans;
        int start = intervals[0].start;
        int end = intervals[0].end;
        for (auto i : intervals) {
            if (end < i.start) {
                ans.push_back(Interval{start, end});
                start = i.start;
                end = i.end;
            } else {
                end = max(end, i.end); // bug
            }
        }
        ans.push_back(Interval{start, end});

        return ans;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
