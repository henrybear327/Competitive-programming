#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

struct Point {
    int dim;
    int val[5];
};

struct Node {
    int mx, mn;
};

struct SegmentTree {
    int operationMask;
    int n;
    Node data[1 << 20];

    inline int lc(int x) // 1-based
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

    inline void pull(int idx)
    {
        data[idx].mx = max(data[lc(idx)].mx, data[rc(idx)].mx);
        data[idx].mn = min(data[lc(idx)].mn, data[rc(idx)].mn);
    }

    void init(int _n, Point points[])
    {
        n = _n;
        init(points, 1, 0, n);
    }

    int getVal(const Point &point)
    {
        int val = 0;
        for (int i = 0; i < point.dim; i++) {
            if ((operationMask >> i) & 1)
                val += 1 * point.val[i];
            else
                val += -1 * point.val[i];
        }
        return val;
    }

    void init(Point points[], int idx, int lb, int rb) // [lb, rb)
    {
        if (rb - lb == 1) {
            int val = getVal(points[lb]);
            data[idx].mx = data[idx].mn = val;
            return;
        }

        int m = mid(lb, rb);
        init(points, lc(idx), lb, m);
        init(points, rc(idx), m, rb);

        pull(idx);
    }

    void update(int who, int idx, int lb, int rb, const Point &newPoint)
    {
        if (rb - lb == 1 && who == lb) {
            int val = getVal(newPoint);
            data[idx].mx = data[idx].mn = val;
            return;
        }

        if (who < mid(lb, rb))
            update(who, lc(idx), lb, mid(lb, rb), newPoint);
        else
            update(who, rc(idx), mid(lb, rb), rb, newPoint);

        pull(idx);
    }

    void update(int who, const Point &newPoint)
    {
        update(who, 1, 0, n, newPoint);
    }

    int query(int l, int r, int idx, int lb, int rb, bool isGetMin)
    {
        if (rb <= l || r <= lb)
            return isGetMin ? INT_MAX : INT_MIN;

        if (l <= lb && rb <= r) {
            if (isGetMin)
                return data[idx].mn;
            return data[idx].mx;
        }

        int m = mid(lb, rb);
        int ret1 = query(l, r, lc(idx), lb, m, isGetMin);
        int ret2 = query(l, r, rc(idx), m, rb, isGetMin);

        if (isGetMin)
            return min(ret1, ret2);
        return max(ret1, ret2);
    }

    int getMin(int l, int r)
    {
        return query(l, r, 1, 0, n, true);
    }

    int getMax(int l, int r)
    {
        return query(l, r, 1, 0, n, false);
    }

    void print()
    {
        printf("mask %d\n", operationMask);
        for (int i = 1; i <= 4 * n; i++)
            printf("%d -> %d %d\n", i, data[i].mx, data[i].mn);
    }
} segmentTree[32];

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    Point points[n];
    for (int i = 0; i < n; i++) {
        points[i].dim = k;
        for (int j = 0; j < k; j++)
            scanf("%d", &points[i].val[j]);
    }

    for (int i = 0; i < 32; i++) {
        segmentTree[i].operationMask = i;
        segmentTree[i].init(n, points);

        // segmentTree[i].print();
    }

    int q;
    scanf("%d", &q);

    Point newPoint;
    while (q--) {
        int command;
        scanf("%d", &command);

        if (command == 1) {
            int which;
            scanf("%d", &which);
            which--;
            for (int i = 0; i < k; i++)
                scanf("%d", &newPoint.val[i]);
            newPoint.dim = k;
            for (int i = 0; i < 32; i++) {
                segmentTree[i].update(which, newPoint);
                // segmentTree[i].print();
            }
        } else {
            int l, r;
            scanf("%d %d", &l, &r);
            l--;

            int mx = 0;
            for (int i = 0; i < 32; i++) {
                int res =
                    abs(segmentTree[i].getMax(l, r) - segmentTree[i].getMin(l, r));
                // printf("i = %d res = %d mx = %d mn = %d\n", i, res,
                //     segmentTree[i].getMax(l, r), segmentTree[i].getMin(l, r));
                mx = max(mx, res);
            }

            printf("%d\n", mx);
        }
    }

    return 0;
}
