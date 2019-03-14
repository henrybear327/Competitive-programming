/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution
{
public:
    vector<Interval> merge(vector<Interval> &intervals)
    {
        vector<Interval> ans;

        if (intervals.size() == 0)
            return ans;

        sort(
            intervals.begin(), intervals.end(),
        [](const Interval &a, const Interval &b) {
            return a.start < b.start;
        });

        cout << intervals.size() << endl;

        int l = intervals[0].start, r = intervals[0].end;
        for (auto i : intervals) {
            if (r < i.start) {
                ans.push_back(Interval{l, r});
                l = i.start;
                r = i.end;
            } else {
                r = max(r, i.end);
            }
        }

        ans.push_back(Interval{l, r});
        return ans;
    }
};
