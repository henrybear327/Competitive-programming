#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

bool solve()
{
    char inp[111];
    scanf("%s", inp);
    int len = strlen(inp);

    if (len > 26)
        return false;

    int cnt[26] = {0};
    for (int i = 0; i < len; i++) {
        cnt[inp[i] - 'a']++;
        if (cnt[inp[i] - 'a'] > 1)
            return false;
    }

    for (int i = 0; i < 26; i++) {
        if (cnt[i] == 1) {
            for (int j = i; j < 26; j++) {
                if (cnt[j] == 0) {
                    for (int k = j; k < 26; k++) {
                        if (cnt[k] == 1)
                            return false;
                    }
                    return true;
                }
            }
        }
    }
    return true;
}

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while (ncase--) {
        printf("%s\n", solve() ? "Yes" : "No");
    }

    return 0;
}
