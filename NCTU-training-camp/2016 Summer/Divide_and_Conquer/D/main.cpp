#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    if (k == 1) {
        printf("0\n");
        return 0;
    }

    int inp[n];
    set<int> s;
    for (int i = 0; i < n; i++) {
        int cur;
        scanf("%d", &cur);
        inp[i] = cur;

        s.insert(cur);
    }

    bool used[n];
    memset(used, 0, sizeof(used));

    sort(inp, inp + n);
    for (int i = 0; i < n; i++) {
        if(s.find(inp[i] / k)
    }

printf("%d\n", (int)s.size());

    return 0;
}
