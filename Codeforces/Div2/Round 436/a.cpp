#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    int cnt[111] = {0};

    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);

        cnt[num]++;
    }

    vector<int> ans;
    for (int i = 0; i < 111; i++) {
        if (cnt[i] != 0) {
            // printf("%d\n", i);
            ans.push_back(i);
        }
    }

    bool ok = (ans.size() == 2) && (cnt[ans[0]] == cnt[ans[1]]);
    printf("%s\n", ok ? "YES" : "NO");
    if (ok)
        printf("%d %d\n", ans[0], ans[1]);

    return 0;
}
