#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    char inp[n + 10];
    scanf("%s", inp);

    int ans = 0;
    set<int> cnt;
    for (int i = 0; i < n; i++) {
        if ('A' <= inp[i] && inp[i] <= 'Z') {
            ans = max(ans, (int)cnt.size());

            cnt.clear();
        } else {
            cnt.insert(inp[i]);
        }
    }
    ans = max(ans, (int)cnt.size());

    printf("%d\n", ans);

    return 0;
}
