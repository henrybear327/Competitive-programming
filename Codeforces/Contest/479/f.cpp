#include <bits/stdc++.h>

using namespace std;

// attempt to append val - 1

int main()
{
    int n;
    scanf("%d", &n);

    int inp[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &inp[i]);

    map<int, int> firstOcc;
    int ans[n];
    int pre[n]; // must record this, since the pos will be changed all the time
    fill(ans, ans + n, 1);
    for (int i = 0; i < n; i++) {
        pre[i] = i;
        firstOcc[inp[i]] =
            i; // can't just keep the first occ position! try 2 3 4 1 2 3 8
        auto it = firstOcc.find(inp[i]);
        if (it != firstOcc.begin()) {
            it--;
            if (it->first + 1 == inp[i]) {
                ans[i] = ans[it->second] + 1;
                pre[i] = it->second;
            }
        }
    }

    /*for (int i = 0; i < n; i++)
        printf("%d ", pre[i]);
    printf("\n");*/

    int mx;
    printf("%d\n", (mx = *max_element(ans, ans + n)));

    for (int i = 0; i < n; i++)
        if (ans[i] == mx) {
            vector<int> res;
            int who = i;
            res.push_back(i);
            while (pre[who] != who) {
                res.push_back(pre[who]);
                who = pre[who];
            }
            reverse(res.begin(), res.end());
            for (auto j : res)
                printf("%d ", j + 1);
            break;
        }

    return 0;
}
