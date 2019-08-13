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

    // 9 1 14 5 5 4 4 14
    // 1 4 4 5 5 9 14 14

    // 9 1 4 4 6 7
    // 1 4 4 6 7 9

    if (inp[n / 2 - 1] == inp[n / 2])
        printf("0\n");
    else
        printf("%d\n", inp[n / 2] - inp[n / 2 - 1]);

    return 0;
}
