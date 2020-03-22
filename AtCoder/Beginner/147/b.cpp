#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    char inp[111];
    scanf("%s", inp);

    int ans = 0;
    int len = strlen(inp);
    for (int i = 0; i < len / 2; i++)
        if (inp[i] != inp[len - i - 1])
            ans++;

    printf("%d\n", ans);

    return 0;
}
