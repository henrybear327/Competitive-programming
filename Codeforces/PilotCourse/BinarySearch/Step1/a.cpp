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

bool __binary_search(int inp[], int n, int target)
{
    int l = 0, r = n;
    while (r - l > 1) {
        int mid = l + (r - l) / 2;
        if (inp[mid] == target)
            return true;
        else if (inp[mid] < target)
            l = mid;
        else
            r = mid;
    }

    return inp[l] == target;
}

bool __binary_search_2(int inp[], int n, int target)
{
    int idx = __my_lower_bound(inp, n, target);
    return idx != n && inp[idx] == target;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    int inp[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &inp[i]);

    for (int i = 0; i < k; i++) {
        int num;
        scanf("%d", &num);

        // printf("%s\n", __binary_search(inp, inp + n, num) ? "YES" : "NO");
        printf("%s\n", __binary_search_2(inp, n, num) ? "YES" : "NO");
    }

    return 0;
}
