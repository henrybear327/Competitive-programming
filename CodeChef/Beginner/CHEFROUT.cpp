#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int getType(char c)
{
    if(c == 'C')
        return 0;
    else if(c == 'E')
        return 1;
    else
        return 2;
}

void solve()
{
    char inp[100010];
    scanf("%s", inp);

    int len = strlen(inp);
    int mx = getType(inp[0]);;
    bool ok = true;
    for(int i = 1; i < len; i++) {
        int state = getType(inp[i]);

        if(state == mx)
            continue;

        if(state < mx)
            ok = false;

        if(state > mx)
            mx = state;
    }

    printf("%s\n", ok ? "yes" : "no");
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
