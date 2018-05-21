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
class MedianFinder
{
private:
	priority_queue<int> left;
	priority_queue<int, vector<int>, greater<int>> right;

public:
	/** initialize your data structure here. */
	MedianFinder() {}

	void addNum(int num)
	{
		left.push(num);
		// if the incoming element shouldn't be at the left, it will be moved wow:)
		right.push(left.top());
		left.pop();
		if (right.size() > left.size()) {
			left.push(right.top());
			right.pop();
		}

		// while (left.size() - right.size() > 1) { // maintain l sz >= r sz
		// 	int cur = left.top();
		// 	left.pop();
		// 	right.push(cur);
		// }

		// while(left.size() > 0 && right.size() > 0 && left.top() > right.top()) {
		// // maintain left top <= right top
		//     int s1 = left.top();
		//     left.pop();
		//     int s2 = right.top();
		//     right.pop();
		//     left.push(s2);
		//     right.push(s1);
		// }
	}

	double findMedian()
	{
		if ((left.size() + right.size()) % 2 == 0) {
			return (1.0 * left.top() + right.top()) / 2;
		} else {
			return left.top();
		}
	}
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */

#ifdef LOCAL
int main()
{
	return 0;
}
#endif