#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);

    ii inp[n];
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);

        inp[i] = {num, i};
    }

    sort(inp, inp + n);

    for (int i = 0; i < n; i++)
        printf("%d%c", inp[i].second + 1, i == n - 1 ? '\n' : ' ');

    return 0;
}
