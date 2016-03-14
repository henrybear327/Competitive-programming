#include <bits/stdc++.h>
// LLONG_MIN LLONG_MAX INT_MIN INT_MAX

using namespace std;

pair<int, int> inp[2 * 1000010];
typedef pair<int, int> ii;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        inp[i * 2].first = a;
        inp[i * 2].second = -1;
        inp[i * 2 + 1].first = b;
        inp[i * 2 + 1].second = 1;
    }

    sort(inp, inp + 2 * n);

    int prev, cnt = 0;
    vector<ii> ans;
    for (int i = 0; i < 2 * n; i++) {
        cnt -= inp[i].second;
        if (inp[i].second == -1 && cnt == k) // left
            prev = inp[i].first;
        else if (inp[i].second == 1 && cnt == k - 1) // right
            ans.push_back(make_pair(prev, inp[i].first));
    }

    printf("%d\n", (int)ans.size());
    for (int i = 0; i < (int)ans.size(); i++)
        printf("%d %d\n", ans[i].first, ans[i].second);

    return 0;
}
