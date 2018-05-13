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

class HitCounter
{
private:
	queue<int> q;

public:
	/** Initialize your data structure here. */
	HitCounter() {}

	/** Record a hit.
	    @param timestamp - The current timestamp (in seconds granularity). */
	void hit(int timestamp)
	{
		q.push(timestamp);
	}

	/** Return the number of hits in the past 5 minutes.
	    @param timestamp - The current timestamp (in seconds granularity). */
	int getHits(int timestamp)
	{
		while (q.size() > 0 && q.front() <= timestamp - 300)
			q.pop();
		return q.size();
	}
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */

#ifdef LOCAL
int main()
{
	return 0;
}
#endif