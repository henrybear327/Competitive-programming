#include <bits/stdc++.h>
// LLONG_MIN LLONG_MAX INT_MIN INT_MAX

using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    if (a.second == b.second)
        return b.first < a.first;
    return a.second < b.second;
}

int main()
{
    int n;
    scanf("%d", &n);

    pair<int, int> inp[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &inp[i].first, &inp[i].second);
    }

    sort(inp, inp + n, cmp);

    for (int i = 0; i < n; i++) {
        // printf("%d %d\n", inp[i].first, inp[i].second);
    }

    /*
    3
    22 22
    14 21
    9 25
    */
    int cnt = 1;
    int end_time = inp[0].second, idx = 0;
    for (int i = 1; i < n; i++) {
        if (end_time >= inp[i].first)
            continue;
        if (inp[i].second == inp[idx].second)
            continue;

        end_time = inp[i].second;
        idx = i;
        cnt++;
    }
    printf("%d\n", cnt);

    return 0;
}
