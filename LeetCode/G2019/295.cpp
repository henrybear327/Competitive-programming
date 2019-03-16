class MedianFinder
{
private:
    multiset<int> left, right;

public:
    /** initialize your data structure here. */
    MedianFinder() {}

    void addNum(int num)
    {
        left.insert(num);
        if (left.size() - right.size() > 1) {
            right.insert(*left.rbegin());
            left.erase(prev(left.end()));
        }

        // oops
        if (left.size() > 0 && right.size() > 0 &&
            *left.rbegin() > *right.begin()) {
            int tmp = *left.rbegin();
            left.erase(prev(left.end()));
            int tmp2 = *right.begin();
            right.erase(right.begin());
            right.insert(tmp);
            left.insert(tmp2);
        }
    }

    double findMedian()
    {
        if ((left.size() + right.size()) % 2 == 0)
            return 1.0 * (*left.rbegin() + *right.begin()) / 2;
        return *left.rbegin();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */