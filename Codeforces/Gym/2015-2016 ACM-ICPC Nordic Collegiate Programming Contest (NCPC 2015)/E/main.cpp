#include <bits/stdc++.h>
// LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;

ii inp[100010];

bool cmp(ii a, ii b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}
int main()
{
    int n, k;
    while (scanf("%d %d", &n, &k) == 2) {
        for (int i = 0; i < n; i++) {
            int x, y;
            scanf("%d %d", &x, &y);

            inp[i] = ii(x, y);
        }
        sort(inp, inp + n, cmp);

        multiset<int, greater<int>> s;
        int ans = 0;
        for (int i = 0; i < k; i++)
            s.insert(0);
        // for(auto i : s)
        // printf("s %d\n", i);
        for (int i = 0; i < n; i++) {
            auto it = s.lower_bound(inp[i].first);
            // printf("%d lb %d\n", inp[i].first, it == s.end() ? -1 : *it);
            if (it != s.end()) {
                s.erase(it);
                s.insert(inp[i].second);
                ans++;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}
