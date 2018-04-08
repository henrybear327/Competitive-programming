#include <bits/stdc++.h>

using namespace std;

int eval(string inp)
{
    int res = 0, base = 1;
    for (int i = 0; i < (int)inp.length(); i++) {
        if (inp[i] == 'S')
            res += base;
        else
            base *= 2;
    }
    return res;
}

// look for the quick way to let 
// 1a + 2b + 4c + 8d + ... <= target
// Move all S as left as it can, while checking the result on the way
void solve()
{
    int limit;
    scanf("%d", &limit);

    char inp[100];
    scanf("%s", inp);
    int len = strlen(inp);

    int cnt = 0;
    while (eval(inp) > limit) {
        bool ok = false;
        for (int i = len - 1; i >= 1; i--) {
            if (inp[i] == 'S' && inp[i - 1] == 'C') {
                swap(inp[i], inp[i - 1]);
                cnt++;
                ok = true;
                break;
            }
        }
        if (ok == false) {
            cnt = -1;
            break;
        }
    }

    printf("%s\n", (cnt == -1 ? "IMPOSSIBLE" : to_string(cnt).c_str()));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int ncase;
    scanf("%d", &ncase);
    for (int i = 1; i <= ncase; i++) {
        printf("Case #%d: ", i);
        solve();
    }

    return 0;
}
