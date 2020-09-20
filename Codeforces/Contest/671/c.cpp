#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

void solve()
{
    int n, target;
    scanf("%d %d", &n, &target);

    vector<int> inp;
    bool hasDrop = false;
    for (int i = 0; i < n; i++) {
        int tmp;
        scanf("%d", &tmp);
        if (target == tmp) {
            hasDrop = true;
            continue;
        }
        inp.push_back(tmp);
    }

    int ans = 0;
    if (inp.size() == 1) {
        ans = 1; // 4 5 5, target 5
    } else if (inp.size() > 0) {
        int sum = 0;
        for (auto i : inp)
            sum += i;

        if (sum == target * (int)inp.size()) {
            ans = 1;
        } else {
            if (hasDrop)
                ans = 1;
            else
                ans = 2;
        }
    }

    printf("%d\n", ans);
}

int main()
{
    int ncase;
    scanf("%d", &ncase);
    while (ncase--)
        solve();

    return 0;
}
