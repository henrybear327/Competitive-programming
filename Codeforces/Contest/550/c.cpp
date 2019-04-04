#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);

    int inp[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &inp[i]);
    sort(inp, inp + n);

    vector<int> ans[2];
    ans[0].push_back(inp[0]);
    for (int i = 1; i < n; i++) {
        if (inp[i] == ans[0].back()) {
            if (ans[1].size() == 0 || (ans[1].size() > 0 && inp[i] != ans[1].back()))
                ans[1].push_back(inp[i]);
            else {
                printf("NO\n");
                return 0;
            }
        } else {
            ans[0].push_back(inp[i]);
        }
    }

    printf("YES\n");
    printf("%d\n", ans[0].size());
    for (auto i : ans[0])
        printf("%d ", i);
    printf("\n");
    printf("%d\n", ans[1].size());
    reverse(ans[1].begin(), ans[1].end());
    for (auto i : ans[1])
        printf("%d ", i);
    printf("\n");

    return 0;
}
