#include <bits/stdc++.h>

using namespace std;

int main()
{
    char inp[100];
    scanf("%s", inp);

    char ans[100] = {'\0'};
    for (int i = 0; i < (int)strlen(inp); i++) {
        int val = 0;
        if (i > 0)
            val += inp[i - 1] - 'A';
        else
            val += 0;

        if (i < (int)strlen(inp) - 1)
            val += inp[i + 1] - 'A';
        else
            val += 0;

        val %= 26;
        printf("%d %d\n", i, val);
        ans[i] = val + 'A';
    }

    printf("%s\n", ans);

    return 0;
}
