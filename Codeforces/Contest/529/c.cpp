#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    if (k < __builtin_popcount(n) || k > n) {
        printf("NO\n");
        return 0;
    }

    priority_queue<int> ans;
    int who = 1;
    while (n > 0) {
        if (n & 1)
            ans.push(who);
        n >>= 1;
        who <<= 1;
    }

    while ((int)ans.size() < k && ans.top() != 1) {
        int cur = ans.top();
        ans.pop();
        if (cur == 2) {
            ans.push(1);
            ans.push(1);
        } else {
            ans.push(cur / 2);
            ans.push(cur / 2);
        }
    }

    if ((int)ans.size() == k) {
        printf("YES\n");
        while (ans.size() > 0) {
            printf("%d ", ans.top());
            ans.pop();
        }
    } else {
        printf("NO\n");
    }

    return 0;
}
