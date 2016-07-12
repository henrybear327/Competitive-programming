#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int cal(int num)
{
    int res = 0;
    while (num) {
        if (num & 1)
            return res;
        num >>= 1;
        res++;
    }

    return res;
}

int main()
{
    int n;
    scanf("%d", &n);

    int inp[n];

    int mn = 0;
    for (int i = 0; i < n; i++) {
        int tmp;
        scanf("%d", &tmp);

        inp[i] = tmp;
        mn = max(mn, cal(tmp));
    }

    int cnt = 0;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if ((inp[i] >> mn) & 1) {
            cnt++;
            ans.push_back(inp[i]);
        }
    }

    if (cnt == 0)
        printf("-1\n");
    else {
        printf("%d\n", cnt);
        for (auto i : ans)
            printf("%d ", i);
    }

    return 0;
}
