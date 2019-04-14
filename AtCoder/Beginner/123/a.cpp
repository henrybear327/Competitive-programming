#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int inp[5];
    for (int i = 0; i < 5; i++)
        scanf("%d", &inp[i]);
    sort(inp, inp + 5);

    int k;
    scanf("%d", &k);

    if (inp[4] - inp[0] <= k)
        printf("Yay!\n");
    else
        printf(":(\n");

    return 0;
}
