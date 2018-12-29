#include <bits/stdc++.h>

#define N 100100

using namespace std;

int inp[N], max_so_far[N], min_so_far[N];

/*
10
1 2 2 2 2 2 2 2 2 1
ans:2
*/

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        scanf("%d", &inp[i]);

    max_so_far[0] = -1;
    /*
    紀錄從頭到現在為止的最大數字
    */
    for (int i = 1; i <= n; i++)
        max_so_far[i] = max(max_so_far[i - 1], inp[i]);

    min_so_far[n] = inp[n];
    /*
    記錄從尾到此的最小數字
    */
    for (int i = n - 1; i >= 1; i--)
        min_so_far[i] = min(min_so_far[i + 1], inp[i]);

    int cnt = 0;
    /*
    1. min_so_far[i + 1] > max_so_far[i], 代表說在位置i之後的數字比現在位置還大，因此為了切出最多區間，所以區間數+1
    2. min_so_far[i + 1] == max_so_far[i]，代表說在位置i之後的數字現在位置的一樣大小，因此為了切出最多區間，所以區間數+1
    3. min_so_far[i + 1] < max_so_far[i]，代表說在位置i之後還有數字比現在位置還要小的，因此代表他們要歸在同一個區間中
    */
    for (int i = 1; i <= n; i++)
        if (min_so_far[i] >= max_so_far[i - 1])
            cnt++;

    printf("%d\n", cnt);

    return 0;
}
