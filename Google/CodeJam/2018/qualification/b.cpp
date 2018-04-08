#include <bits/stdc++.h>

using namespace std;

// the observation is that
// even-index positions can only move to even-index positions
// odd-index positions can only move to odd-index positions
string solve()
{
    int n;
    scanf("%d", &n);

    vector<int> inp(n, 0);
    unordered_multiset<int> odd, even;
    for (int i = 0; i < n; i++) {
        scanf("%d", &inp[i]);

        if (i % 2 == 0)
            even.insert(inp[i]);
        else
            odd.insert(inp[i]);
    }
    sort(inp.begin(), inp.end());

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            auto it = even.find(inp[i]);
            if (it == even.end())
                return to_string(i);

            even.erase(it);
        } else {
            auto it = odd.find(inp[i]);
            if (it == odd.end())
                return to_string(i);

            odd.erase(it);
        }
    }

    return "OK";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int ncase;
    scanf("%d", &ncase);
    for (int i = 1; i <= ncase; i++) {
        printf("Case #%d: ", i);
        printf("%s\n", solve().c_str());
    }

    return 0;
}
