# Notes

### 11995

Check for poping elements out of empty stack/queue/priority queue error!!

### 10954

Simulate the process by hand first!!! It saves time!

### 1203

Just know how to send cmp function to priority_queue will be good enough to solve this problem.

```
typedef struct container {
    int idx, time, interval;
} Container;

struct cmp {
    bool operator()(Container const &p1, Container const &p2) {
        if (p1.time == p2.time)
            return p1.idx > p2.idx;
        return p1.time > p2.time;
    }
};
```

Notice that the sign differs from `sort()` and other containers' cmp function
