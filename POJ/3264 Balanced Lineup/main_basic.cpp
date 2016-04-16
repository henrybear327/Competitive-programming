#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

#define N 50010
#define lc(x) (x << 1)
#define rc(x) ((x << 1) + 1)
int inp[N];
struct SegmentTreeMax {
    int *tree;
    int nn;

    void init(int n)
    {
        nn = n;
        int depth = 1;
        while( (1 << depth++) < n); // get the depth of original input data. Depth is 1-based.

        tree = (int *) malloc((1 << depth) * sizeof(int)); // total nodes needed for a segment tree

        //printf("Going to build\n");
        build(1, 0, n - 1);
        //printf("Build complete\n");
    }

    void build(int idx, int l, int r) // [l, r] = [0, n -1] --> bound of the input data
    {
        //printf("%d %d %d\n", idx, l, r);
        if(l == r) { // it's currently on leaf node
            tree[idx] = inp[l];
            return; // this is crucial!!!
        }

        int mid = (l + r) / 2;
        build(lc(idx), l, mid);
        build(rc(idx), mid + 1, r);

        tree[idx] = max(tree[lc(idx)], tree[rc(idx)]); // update current node with the max value of children
    }

    int query(int i, int j)
    {
        return query(1, 0, nn - 1, i, j);
    }
    int query(int idx, int l, int r, int i, int j)
    {
        //printf("%d %d %d %d %d\n", idx, l, r, i, j);
        if(l == i && j == r) { // case 1: complete interval overlap
            return tree[idx];
        }

        int mid = (l + r) / 2;
        if(i <= mid && mid + 1 <= j) { // split the interval
            //printf("Split\n");
            return max(query(lc(idx), l, mid, i, mid), query(rc(idx), mid + 1, r, mid + 1, j));
        } else if(j <= mid) // only left
            return query(lc(idx), l, mid, i, j);
        else // only right
            return query(rc(idx), mid + 1, r, i, j);
    }
};

struct SegmentTreeMin {
    int *tree;
    int nn;

    void init(int n)
    {
        nn = n;
        int depth = 1;
        while( (1 << depth++) < n); // get the depth of original input data. Depth is 1-based.

        tree = (int *) malloc((1 << depth) * sizeof(int)); // total nodes needed for a segment tree

        //printf("Going to build\n");
        build(1, 0, n - 1);
        //printf("Build complete\n");
    }

    void build(int idx, int l, int r) // [l, r] = [0, n -1] --> bound of the input data
    {
        //printf("%d %d %d\n", idx, l, r);
        if(l == r) { // it's currently on leaf node
            tree[idx] = inp[l];
            return; // this is crucial!!!
        }

        int mid = (l + r) / 2;
        build(lc(idx), l, mid);
        build(rc(idx), mid + 1, r);

        tree[idx] = min(tree[lc(idx)], tree[rc(idx)]); // update current node with the min value of children
    }

    int query(int i, int j)
    {
        return query(1, 0, nn - 1, i, j);
    }
    int query(int idx, int l, int r, int i, int j)
    {
        //printf("%d %d %d %d %d\n", idx, l, r, i, j);
        if(l == i && j == r) { // case 1: complete interval overlap
            return tree[idx];
        }

        int mid = (l + r) / 2;
        if(i <= mid && mid + 1 <= j) { // split the interval
            //printf("Split\n");
            return min(query(lc(idx), l, mid, i, mid), query(rc(idx), mid + 1, r, mid + 1, j));
        } else if(j <= mid) // only left
            return query(lc(idx), l, mid, i, j);
        else // only right
            return query(rc(idx), mid + 1, r, i, j);
    }
};


int main()
{
    int n, q;
    while(scanf("%d %d", &n, &q) == 2) {
        for(int i = 0; i < n; i++)
            scanf("%d", &inp[i]);
        SegmentTreeMax maxTree;
        maxTree.init(n);
        SegmentTreeMin minTree;
        minTree.init(n);

        for(int i = 0; i < q; i++) {
            int l, r;
            scanf("%d %d", &l, &r);
            l--;
            r--;
            printf("%d\n", maxTree.query(l, r) - minTree.query(l, r));
        }
    }

    return 0;
}