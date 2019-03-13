#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);

    vector<int> inp;
    int cnt = 0, type = -1;
    for (int i = 0; i < n; i++) {
        int cur;
        scanf("%d", &cur);

        if (type == -1)
            type = cur, cnt++;
        else if (type == cur)
            cnt++;
        else {
            inp.push_back(cnt);
            cnt = 1;
            type = cur;
        }
    }

    inp.push_back(cnt);

    int ans = 0;
    for (int i = 0; i < (int)inp.size() - 1; i++)
        ans = max(ans, min(inp[i], inp[i + 1]) * 2);

    printf("%d\n", ans);

    return 0;
}
