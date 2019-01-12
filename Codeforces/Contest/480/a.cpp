#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    char inp[111];
    scanf("%s", inp);

    int len = strlen(inp);
    int cnt[2] = {0};
    for (int i = 0; i < len; i++) {
        if (inp[i] == '-')
            cnt[0]++; // -
        else
            cnt[1]++; // o
    }

    if ((cnt[1] <= 1) || (cnt[0] % cnt[1] == 0))
        printf("YES\n");
    else {
        printf("NO\n");
    }

    return 0;
}
