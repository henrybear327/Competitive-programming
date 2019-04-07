#include <bits/stdc++.h>

using namespace std;

typedef pair<pair<int, int>, int> restriction;
typedef pair<int, int> ii;

string solve()
{
    string ans;

    int n;
    char inp[55555 * 2];
    scanf("%d %s", &n, inp);

    int l = strlen(inp);
    for (int i = 0; i < l; i++) {
        inp[i] = (inp[i] == 'S' ? 'E' : 'S');
    }

    return inp;
}

int main()
{
    int ncase;
    scanf("%d", &ncase);
    for (int i = 1; i <= ncase; i++) {
        auto res = solve();
        printf("Case #%d: %s\n", i, res.c_str());
    }
}
