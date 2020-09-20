#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

void solve()
{
    int n;
    scanf("%d", &n);

    char inp[n + 3];
    scanf("%s", inp);

    vector<int> a, b;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            a.push_back(inp[i] - '0');
        } else {
            b.push_back(inp[i] - '0');
        }
    }

    sort(a.begin(), a.end(), [](const int _a, const int _b) {
        int aa = _a % 2;
        int bb = _b % 2;

        return aa < bb;
    });
    sort(b.begin(), b.end(), [](const int _a, const int _b) {
        int aa = _a % 2;
        int bb = _b % 2;

        return aa > bb;
    });

    if (n % 2 == 0) {
        printf("%d\n", b.back() % 2 == 0 ? 2 : 1);
    } else {
        printf("%d\n", a.back() % 2 == 0 ? 2 : 1);
    }
}

int main()
{
    int ncase;
    scanf("%d", &ncase);
    while (ncase--)
        solve();

    return 0;
}
