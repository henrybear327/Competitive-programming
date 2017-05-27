#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

void solve()
{
    char s1[111], s2[111];
    scanf("%s %s", s1, s2);

    int len_s1 = strlen(s1), len_s2 = strlen(s2);
    int res = 0;
    for (int i = 0; i < len_s2; i++) {
        for (int j = 0; j < len_s1; j++) {
            if (s2[i] == s1[j]) {
                res++;
                break;
            }
        }
    }
    printf("%d\n", res);
}

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while (ncase--) {
        solve();
    }

    return 0;
}
