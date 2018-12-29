#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    vector<vector<int>> subject(m);
    for (int i = 0; i < n; i++) {
        int s, r;
        scanf("%d %d", &s, &r);
        s--;

        subject[s].push_back(r);
    }

    for (int i = 0; i < m; i++) {
        sort(subject[i].begin(), subject[i].end());
        reverse(subject[i].begin(), subject[i].end());
    }

    int sum[n] = {0};
    for (int i = 0; i < m; i++) {
        int prefix = 0;
        for (int j = 0; j < (int)subject[i].size(); j++) {
            if (prefix + subject[i][j] >= 0) {
                prefix += subject[i][j];
                sum[j] += prefix;
            } else {
                break;
            }
        }
    }

    int mx = 0;
    for (int i = 0; i < n; i++)
        mx = max(mx, sum[i]);

    printf("%d\n", mx);

    return 0;
}
