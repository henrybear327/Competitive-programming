#include <bits/stdc++.h>
// LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    int h[60] = {0}, v[60] = {0};
    vector<int> ans;
    int cnt = 0;
    for (int i = 0; i < n * n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        if (h[a] == 0 && v[b] == 0) {
            h[a] = v[b] = 1;
            ans.push_back(i);
            cnt++;
        }
    }

    for (int i = 0; i < cnt; i++)
        printf("%d%c", ans[i] + 1, cnt == i + 1 ? '\n' : ' ');

    return 0;
}
