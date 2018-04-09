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

class MovingAverage
{
private:
    deque<int> window;
    int size, sum;

public:
    /** Initialize your data structure here. */
    MovingAverage(int _size)
    {
        size = _size;
        sum = 0;
        window.clear();
    }

    double next(int val)
    {
        window.push_back(val);
        sum += val;
        if ((int)window.size() <= size)
            return 1.0 * sum / window.size();
        sum -= window.front();
        window.pop_front();
        return 1.0 * sum / window.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */

#ifdef LOCAL
int main()
{
    return 0;
}
#endif