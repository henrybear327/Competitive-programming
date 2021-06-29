#include <bits/stdc++.h>

using namespace std;

// returns the first element that is not less than target
// 10 10 20 20 20 30 40; target = 20
//       ^
//
// If all the elements in the range compare less than target, the function
// returns last
int __my_lower_bound(int inp[], int n, int target)
{
    int l = -1, r = n;
    while (r - l > 1) {
        int mid = l + (r - l) / 2;
        // xxvvvv
        //  lr
        if (target <= inp[mid])
            r = mid;
        else
            l = mid;
    }

    return r;
}

// returns the first element that is greater than target
// 10 10 20 20 20 30 40; target = 20
//                ^
//
// If none of the elements in the range compare greater than target, the
// function returns last
int __my_upper_bound(int inp[], int n, int target)
{
    int l = -1, r = n;
    while (r - l > 1) {
        int mid = l + (r - l) / 2;
        // xxxxvv
        //    lr
        if (target < inp[mid])
            r = mid;
        else
            l = mid;
    }

    return r;
}

int main()
{
    int n;
    scanf("%d", &n);

    int inp[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &inp[i]);
    sort(inp, inp + n);

    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        int l, r;
        scanf("%d %d", &l, &r);

        // 1 3 4 10 10
        // [2, 10)
        printf("%d\n", __my_upper_bound(inp, n, r) - __my_lower_bound(inp, n, l));
    }

    return 0;
}
