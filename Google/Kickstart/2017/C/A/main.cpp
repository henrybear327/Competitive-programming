#include <bits/stdc++.h>

using namespace std;

string solve()
{
    char inp[55];
    scanf("%s", inp);

    int len = strlen(inp);
    if (len % 2 == 1)
        return "AMBIGUOUS";

    char ans[len + 1];
    memset(ans, '\0', sizeof(ans));

    ans[1] = inp[0];
    ans[len - 2] = inp[len - 1];

    for (int i = 1 + 2; i < len; i += 2) {
        int ref = inp[i - 1] - 'A';
        int prev = ans[i - 2] - 'A';

        int ret = (ref - prev + 26) % 26;
        ans[i] = ret + 'A';
    }

    for (int i = len - 2 - 2; i >= 0; i -= 2) {
        int ref = inp[i + 1] - 'A';
        int prev = ans[i + 2] - 'A';

        int ret = (ref - prev + 26) % 26;
        ans[i] = ret + 'A';
    }

    return ans;
}

int main()
{
    int ncase;
    scanf("%d", &ncase);
    for (int i = 1; i <= ncase; i++) {
        printf("Case #%d: %s\n", i, solve().c_str());
    }
}
