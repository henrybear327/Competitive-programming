#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    char inp[n];
    scanf("%s", inp);

    int mx = 0;
    for (int i = 1; i <= n - 1; i++) {
        if (strncmp(inp, inp + n - i, i) == 0)
            mx = i;
    }

    printf("%s", inp);
    for (int i = 1; i < k; i++) {
        for (int j = mx; j < n; j++)
            printf("%c", inp[j]);
    }
    printf("\n");

    return 0;
}
