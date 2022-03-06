#include <bits/stdc++.h>

using namespace std;

int main()
{
    char inp[1000003];
    scanf("%s", inp);

    int len = strlen(inp);
    int ans = 0;
    for (int i = 0; i < len; i++) {
        int j;
        for (j = i; j < len && inp[i] == inp[j]; j++) {
            ans = max(j - i + 1, ans);
        }
        i = j - 1;
    }

    printf("%d\n", ans);

    return 0;
}
