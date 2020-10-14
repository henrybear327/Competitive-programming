#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    int inp[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &inp[i]);
    }
    sort(inp, inp + n);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int j = i + 1;
        for (; j < n && inp[i] == inp[j]; j++)
            ;
        ans++;

        i = j - 1;
    }

    printf("%d\n", ans);

    return 0;
}
