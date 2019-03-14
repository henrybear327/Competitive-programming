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
    int minMeetingRooms(vector<Interval> &intervals)
    {
        int ans = 0;

        sort(intervals.begin(), intervals.end(),
        [](const Interval &a, const Interval &b) {
            if (a.start == b.start)
                return a.end < b.end;
            return a.start < b.start;
        });

        int cnt = 0;
        set<int> s;
        for (auto i : intervals) {
            while (s.size() > 0 && *s.begin() <= i.start) {
                cnt--;
                s.erase(s.begin());
            }
            cnt++;
            s.insert(i.end);
            ans = max(ans, cnt);
        }

        return ans;
    }
};
