#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    char inp[10 + 3];
    scanf("%s", inp);

    int ans = 0;
    for (int i = 0; i < (int)strlen(inp); i++) {
        for (int j = 0; j < (int)strlen(inp); j++) {
            for (int k = i; k <= j; k++) {
                char c = inp[k];
                if (c == 'A' || c == 'T' || c == 'G' || c == 'C')
                    continue;
                else
                    goto fail;
            }
            ans = max(ans, j - i + 1);
fail:
            continue;
        }
    }
    printf("%d\n", ans);

    return 0;
}
