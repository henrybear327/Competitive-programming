#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    deque<int> q;

    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);

        q.push_back(num);
    }

    int ans = 0;
    while (q.size() > 0) {
        if (q.front() <= k)
            q.pop_front();
        else if (q.back() <= k)
            q.pop_back();
        else
            break;
        ans++;
    }

    printf("%d\n", ans);

    return 0;
}
