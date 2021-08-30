#include <bits/stdc++.h>

using namespace std;

bool isVowel(char c)
{
    if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        return true;
    return false;
}

int solve()
{
    char inp[103];
    scanf("%s", inp);

    int len = strlen(inp);
    int mn = INT_MAX;
    for (int i = 0; i < 26; i++) {
        char toChar = 'A' + i;

        int t = 0;
        for (int j = 0; j < len; j++) {
            if (inp[j] == toChar) {
                continue;
            }

            if (isVowel(inp[j]) == isVowel(toChar)) {
                t += 2;
            } else {
                t++;
            }
        }

        mn = min(mn, t);
    }
    return mn;
}

int main()
{
    int ncase;
    scanf("%d", &ncase);

    for (int i = 1; i <= ncase; i++) {
        printf("Case #%d: %d\n", i, solve());
    }

    return 0;
}
