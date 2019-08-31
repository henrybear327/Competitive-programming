typedef pair<int, int> ii;

class Solution
{
public:
    //     int minMeetingRooms(vector<vector<int>>& intervals) {
    //         if (intervals.size() == 0) // 0 case
    //             return 0;

    //         vector<ii> transformed;
    //         transformed.reserve(2 * intervals.size());
    //         for(const auto &i : intervals) {
    //             transformed.push_back(ii(i[0], 1));
    //             transformed.push_back(ii(i[1], -1));
    //         }

    //         sort(transformed.begin(), transformed.end(), [](const ii &a, const
    //         ii &b) {
    //             if(a.first == b.first)
    //                 return a.second < b.second;
    //             return a.first < b.first;
    //         });

    //         int acc = 1, mx = 1; // 1 case
    //         for(int i = 1; i < (int)transformed.size(); i++) {
    //             acc += transformed[i].second;
    //             mx = max(mx, acc);
    //         }

    //         return mx;
    //     }

    // Approach 2: Chronological Ordering = use two pointer to replace 1/-1
    int minMeetingRooms(vector<vector<int>> &intervals)
    {
        if (intervals.size() == 0) // 0 case
            return 0;

        int s[intervals.size()], e[intervals.size()];
        int idx = 0;
        for (auto i : intervals)
            s[idx] = i[0], e[idx] = i[1], idx++;
        sort(s, s + intervals.size());
        sort(e, e + intervals.size());

        idx = 0;
        int idx2 = 0;
        int mx = 0, cnt = 0;
        while (idx < intervals.size()) {
            while (idx < intervals.size() && s[idx] < e[idx2]) {
                cnt++;
                idx++;
            }
            mx = max(cnt, mx);
            idx2++;
            cnt--;
        }

        return mx;
    }
};
