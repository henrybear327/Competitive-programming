#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

bool ok(string str)
{
    // cout << str << endl;
    int n = str.length();
    for (int i = 0; i < n / 2; i++)
        if (str[i] != str[n - i - 1])
            return false;

    return true;
}

int main()
{
    char ip[111];
    scanf("%s", ip);

    string inp(ip);
    int n = strlen(ip);
    if (ok(inp) && ok(inp.substr(0, (n - 1) / 2)) &&
        ok(inp.substr((n + 3) / 2 - 1, n)))
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}
