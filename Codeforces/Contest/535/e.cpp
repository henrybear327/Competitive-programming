#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

struct Interval {
    int s, t;
    int idx;

    bool operator<(const Interval &other)
    {
        return s < other.s;
    }
};

struct cmp {
    bool operator()(const Interval &a, const Interval &b)
    {
        return a.t > b.t;
    }
};

struct Node {
    int mn, mx;
    int tag;
};

const int N = 1 << 18;

struct SegmentTree { // 1-based, self is up-to-date
    Node data[N];
    int n, maxN = 0;

    inline int lc(int x)
    {
        return x * 2;
    }

    inline int rc(int x)
    {
        return x * 2 + 1;
    }

    inline int mid(int x, int y)
    {
        return (x + y) / 2;
    }

    void init(int seq[], int _n)
    {
        n = _n;
        init(seq, 0, n, 1);
    }

    void init(int seq[], int l, int r, int idx)
    {
        maxN = max(maxN, idx);
        if (r - l == 1) {
            data[idx].mx = data[idx].mn = seq[l];
            data[idx].tag = 0;
            return;
        }

        init(seq, l, mid(l, r), lc(idx));
        init(seq, mid(l, r), r, rc(idx));

        pull(idx);
    }

    void push(int idx)
    {
        int tag = data[idx].tag;

        // update children mn, mx
        data[lc(idx)].mx += tag;
        data[rc(idx)].mx += tag;
        data[lc(idx)].mn += tag;
        data[rc(idx)].mn += tag;

        // update children tag
        data[lc(idx)].tag += tag;
        data[rc(idx)].tag += tag;

        data[idx].tag = 0; // crucial
    }

    void pull(int idx)
    {
        data[idx].mx = max(data[lc(idx)].mx, data[rc(idx)].mx);
        data[idx].mn = min(data[lc(idx)].mn, data[rc(idx)].mn);
    }

    void insert(int s, int t)
    {
        update(s, t, 1, 0, n, -1);
    }

    void remove(int s, int t)
    {
        update(s, t, 1, 0, n, 1);
    }

    void update(int l, int r, int idx, int lb, int rb, int val) // [l, r)
    {
        // printf("%d %d %d %d %d\n", idx, l, r, lb, rb);
        if (r <= lb || rb <= l) // important bound check!
            return;

        // printf("idx %d: %d %d, %d %d\n", idx, l, r, lb, rb);
        if (l <= lb && rb <= r) {
            data[idx].mx += val;
            data[idx].mn += val;

            data[idx].tag += val;
            return;
        }

        push(idx);

        update(l, r, lc(idx), lb, mid(lb, rb), val);
        update(l, r, rc(idx), mid(lb, rb), rb, val);

        pull(idx);
    }

    int getMax()
    {
        return data[1].mx;
    }

    int getMin()
    {
        return data[1].mn;
    }

    void print()
    {
        for (int i = 1; i <= maxN; i++) {
            printf("%d: %d %d %d\n", i, data[i].mn, data[i].mx, data[i].tag);
        }
    }
} segmentTree;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int seq[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &seq[i]);

    Interval interval[m];
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &interval[i].s, &interval[i].t);
        interval[i].s--;
        interval[i].idx = i;
    }
    sort(interval, interval + m);

    segmentTree.init(seq, n);
    // segmentTree.print();

    // for every point, we attempt to make it mn
    int maxDiff = 0;
    int idx = 0;
    set<int> maxDiffIntervalSet, inUse;
    priority_queue<Interval, vector<Interval>, cmp> pq;
    for (int i = 0; i < n; i++) {
        // add all intervals that covers i
        while (idx < m && interval[idx].s == i) {
            segmentTree.insert(interval[idx].s, interval[idx].t);
            pq.push(interval[idx]);
            inUse.insert(interval[idx].idx);
            idx++;

            // printf("ins i = %d\n", i);
            // segmentTree.print();
        }

        // remove all intervals that doesn't cover i now (but previously does)
        while (pq.size() > 0 && pq.top().t <= i) {
            auto cur = pq.top();
            inUse.erase(cur.idx);
            segmentTree.remove(cur.s, cur.t);
            pq.pop();

            // printf("del i = %d\n", i);
            // segmentTree.print();
        }

        // if curDiff < maxDiff, record the intervals used and the max diff
        int curDiff = segmentTree.getMax() - segmentTree.getMin();
        if (curDiff > maxDiff) {
            maxDiff = curDiff;
            maxDiffIntervalSet = inUse;
        }
    }

    printf("%d\n%d\n", maxDiff, (int)maxDiffIntervalSet.size());
    for (auto i : maxDiffIntervalSet)
        printf("%d ", i + 1);

    return 0;
}
