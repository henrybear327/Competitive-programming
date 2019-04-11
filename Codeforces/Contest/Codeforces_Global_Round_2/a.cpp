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

    set<int> seen;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (seen.find(inp[i]) == seen.end()) {
            seen.insert(inp[i]);

            for (int j = n - 1; j > i; j--) {
                if (inp[j] != inp[i]) {
                    ans = max(ans, j - i);
                    break;
                }
            }

            int j = i;
            while (j < n && inp[j] == inp[i])
                j++;
            i = j - 1;
        }
    }

    printf("%d\n", ans);

    return 0;
}
