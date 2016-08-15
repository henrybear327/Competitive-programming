#include <bits/stdc++.h>

using namespace std;

#define N 1024100

struct Data {
    int type;
    int sum;
    int status; // (-1, 0, 1, 2) => (nothing, to 0, to 1, reverse)
};

int result;

#define DEBUG 0

#define lc(x) (2 * x + 1)
#define rc(x) (2 * x + 2)
struct SegmentTree {
    Data data[(1 << 21)];
    int n, mx;

    void init()
    {
        memset(data, -1, sizeof(data));
    }

    void build(char inp[], int _n)
    {
        n = _n;
        mx = 0;
        build(0, 0, n - 1, inp);
        // printf("%d\n", mx);
    }

    void build(int idx, int l, int r, char inp[]) // 0-based,  [l, r]
    {
        mx = max(mx, idx);

        if (l == r) {
            data[idx].type = inp[l] - '0';
            data[idx].sum = inp[l] == '1' ? 1 : 0;

            return;
        }

        int mid = (l + r) / 2;
        build(lc(idx), l, mid, inp);
        build(rc(idx), mid + 1, r, inp);

        data[idx].sum = data[lc(idx)].sum + data[rc(idx)].sum;
    }

    int getStatus(int oldStatus, int newStatus)
    {
        if (newStatus == -1)
            return oldStatus;

        if (oldStatus == -1) {
            return newStatus;
        } else if (oldStatus == 0) {
            if (newStatus == 2)
                return 1;
            return newStatus;
        } else if (oldStatus == 1) {
            if (newStatus == 2)
                return 0;
            return newStatus;
        } else { // 2
            if (newStatus == 2)
                return -1;
            return newStatus;
        }
    }

    void push(int idx, int lb, int rb)
    {
        if (data[idx].status != -1) {
            int status = data[idx].status;

            if (status == 0)
                data[idx].sum = 0;
            else if (status == 1)
                data[idx].sum = (rb - lb + 1);
            else // (status == 2)
                data[idx].sum = (rb - lb + 1) - data[idx].sum;

            if (lb != rb) {
                // lc
                data[lc(idx)].status =
                    getStatus(data[lc(idx)].status, data[idx].status);

                // rc
                data[rc(idx)].status =
                    getStatus(data[rc(idx)].status, data[idx].status);
            }

            data[idx].status = -1;
        }
    }

    int query(int l, int r)
    {
        return query(0, 0, n - 1, l, r);
    }

    int query(int idx, int lb, int rb, int l, int r)
    {
        if (l < lb || r > rb || l > r)
            return 0;

#if DEBUG == 1
        printf("%d %d %d %d %d\n", idx, lb, rb, l, r);
#endif
        push(idx, lb, rb);

        if (lb == l && rb == r) {
            // deal with lazy
            return data[idx].sum;
        }

        int mid = (lb + rb) / 2, res;
        if (r <= mid)
            res = query(lc(idx), lb, mid, l, r);
        else if (l >= mid + 1)
            res = query(rc(idx), mid + 1, rb, l, r);
        else
            res = query(lc(idx), lb, mid, l, mid) +
                  query(rc(idx), mid + 1, rb, mid + 1, r);

        // data[idx].sum = query(lc(idx), lb, mid, lb, mid) + query(rc(idx), mid +
        // 1, rb, mid + 1, rb);
        return res;
    }

    void update(int l, int r, int status)
    {
        update(0, 0, n - 1, l, r, status);
    }

    void update(int idx, int lb, int rb, int l, int r, int status)
    {
#if DEBUG == 1
        printf("%d %d %d %d %d %d\n", idx, lb, rb, l, r, status);
#endif
        push(idx, lb, rb);

        if (lb == l && rb == r) {
            // update cur node using new status
            if (status == 0)
                data[idx].sum = 0;
            else if (status == 1)
                data[idx].sum = (rb - lb + 1);
            else if (status == 2)
                data[idx].sum = (rb - lb + 1) - data[idx].sum;

            // push and merge new status to children
            if (lb != rb) {
                data[lc(idx)].status = getStatus(data[lc(idx)].status, status);
                data[rc(idx)].status = getStatus(data[rc(idx)].status, status);
            }
            return;
        }

        int mid = (lb + rb) / 2;
        if (r <= mid)
            update(lc(idx), lb, mid, l, r, status);
        else if (l >= mid + 1)
            update(rc(idx), mid + 1, rb, l, r, status);
        else {
            update(lc(idx), lb, mid, l, mid, status);
            update(rc(idx), mid + 1, rb, mid + 1, r, status);
        }

        data[idx].sum = query(lc(idx), lb, mid, lb, mid) +
                        query(rc(idx), mid + 1, rb, mid + 1, rb);
    }

    void print()
    {
        for (int i = 0; i <= mx; i++)
            printf("%2d: %2d, %2d\n", i, data[i].sum, data[i].status);
        printf("\n");
    }

} segmentTree;

int main()
{
    /*
    // max nodes needed for segment tree
    int cnt = 0;
    result = N;
    while((1 << cnt) < result) {
            cnt++;
    }
    result = (1 << (cnt + 1));
    printf("%d\n", result);
    */

    int ncase;
    scanf("%d", &ncase);

    int caseCnt = 1;
    while (ncase--) {
        printf("Case %d:\n", caseCnt++);

        segmentTree.init();

        int n;
        scanf("%d", &n);

        int idx = 0;
        char inp[N];

        for (int i = 0; i < n; i++) {
            int times;
            scanf("%d", &times);

            char tmp[N];
            scanf("%s", tmp);
            int len = strlen(tmp);

            for (int j = 0; j < times; j++) {
                for (int k = 0; k < len; k++) {
                    inp[idx++] = tmp[k];
                }
            }
        }
        inp[idx] = '\0';

        // printf("%d\n", strlen(inp));
        // printf("%s\n", inp);

        segmentTree.build(inp, strlen(inp));

#if DEBUG == 1
        segmentTree.print();
#endif

        scanf("%d", &n);
        int queryCnt = 1;
        for (int i = 0; i < n; i++) {
            // char int int
            char tmp[100], c;
            int l, r;
            scanf("%s %d %d", tmp, &l, &r);

            c = tmp[0];
            if (c == 'F') {
                segmentTree.update(l, r, 1);
            } else if (c == 'E') {
                segmentTree.update(l, r, 0);
            } else if (c == 'I') {
                segmentTree.update(l, r, 2);
            } else { // S
                printf("Q%d: %d\n", queryCnt++, segmentTree.query(l, r));
            }

#if DEBUG == 1
            segmentTree.print();
#endif
        }
    }

    return 0;
}
