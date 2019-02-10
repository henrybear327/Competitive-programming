#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    // O (m)
    int starting[m + 1] = {0}, ending[m + 1] = {0};
    for (int i = 0; i < n; i++) {
        int l, r;
        scanf("%d %d", &l, &r);

        starting[l]++;
        ending[r]++;
    }

    int sum = 0;
    vector<int> ans;
    for (int i = 1; i <= m; i++) {
        sum += starting[i];

        if (sum == 0)
            ans.push_back(i);

        sum -= ending[i];
    }

    /* O(n * m)
    bool covered[m + 1];
    memset(covered, false, sizeof(covered));
    for (int i = 0; i < n; i++) {
        int l, r;
        scanf("%d %d", &l, &r);

        for (int j = l; j <= r; j++)
            covered[j] = true;
    }

    vector<int> ans;
    for (int i = 1; i <= m; i++)
        if (covered[i] == false)
            ans.push_back(i);
    */

    printf("%d\n", (int)ans.size());
    for (auto i : ans)
        printf("%d ", i);

    return 0;
}
