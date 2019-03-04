class MovingAverage
{
private:
    int intervalSize;
    queue<int> q;
    int sum;

public:
    /** Initialize your data structure here. */
    MovingAverage(int size)
    {
        intervalSize = size;
        sum = 0;
    }

    double next(int val)
    {
        sum += val;
        q.push(val);
        if (q.size() > intervalSize)
            sum -= q.front(), q.pop();

        return 1.0 * sum / q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
