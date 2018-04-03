#ifdef LOCAL
#include <bits/stdc++.h>
using namespace std;

// tree node stuff here...
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

typedef pair<int, int> ii;
class Solution
{
public:
    int minMeetingRooms(vector<Interval> &intervals)
    {
        // map<int, int> cnt;
        // for (auto interval : intervals) {
        //     cnt[interval.start] += 1;
        //     cnt[interval.end] += -1;
        // }

        // int total = 0, ans = 0;
        // for (auto i : cnt) {
        //     // printf("%d %d\n", i.first, i.second);
        //     total += i.second;
        //     ans = max(ans, total);
        // }
        // return ans;

        vector<ii> arr;
        for (auto i : intervals) {
            arr.push_back(ii(i.start, 1));
            arr.push_back(ii(i.end, -1));
        }
        sort(arr.begin(), arr.end());

        int ans = 0, cnt = 0;
        for (int i = 0; i < (int)arr.size() - 1; i++) { 
            // last item doesn't matter since it's guaranteed to be a -1
            // and we are looking for max
            cnt += arr[i].second;
            if (arr[i].first == arr[i + 1].first)
                continue;
            ans = max(ans, cnt);
        }
        return ans;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif