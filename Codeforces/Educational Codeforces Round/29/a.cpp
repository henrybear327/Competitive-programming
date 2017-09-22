#include <bits/stdc++.h>

using namespace std;

bool check(string &inp)
{
    for (int i = 0; i < (int)inp.length() / 2; i++) {
        if (inp[i] != inp[inp.length() - i - 1])
            return false;
    }
    return true;
}

int main()
{
    string inp;
    cin >> inp;

    reverse(inp.begin(), inp.end());

    bool ok = false;
    for (int i = 0; i < 10; i++) {
        ok = check(inp);

        if (ok)
            break;

        inp += '0';
    }

    printf("%s\n", ok ? "YES" : "NO");

    return 0;
}