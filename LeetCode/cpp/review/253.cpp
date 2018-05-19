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

// handle special cases first
// [], "", ...
// range of input?

typedef pair<int, int> ii;
class Solution
{
public:
	int minMeetingRooms(vector<Interval> &intervals)
	{
		vector<ii> order;
		for (auto i : intervals) {
			order.push_back(ii(i.start, 1));
			order.push_back(ii(i.end, -1));
		}

		sort(order.begin(), order.end());
		int mx = 0, cur = 0;
		for (int i = 0; i < (int)order.size(); i++) {
			cur += order[i].second;
			mx = max(mx, cur);
		}

		return mx;
	}
};

#ifdef LOCAL
int main()
{
	return 0;
}
#endif