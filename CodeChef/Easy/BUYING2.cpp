#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

void solve()
{
    int n, x;
    scanf("%d %d", &n, &x);

    int money = 0;

    vector<int> inp;
    for (int i = 0; i < n; i++) {
        int cur;
        scanf("%d", &cur);

        money += cur;
        inp.push_back(cur);
    }

    int diff = money - (money / x) * x;

    bool error = false;
    for (int i = 0; i < (int)inp.size(); i++) {
        if ((money - inp[i]) / x == money / x)
            error = true;
    }

    printf("%d\n", error ? -1 : money / x);
}

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while (ncase--) {
        solve();
    }

    return 0;
}
