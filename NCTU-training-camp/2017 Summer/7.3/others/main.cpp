// http://codeforces.com/problemset/problem/59/A

#include <bits/stdc++.h>

using namespace std;

char toUpper(char c)
{
    if ('a' <= c && c <= 'z')
        return c - 'a' + 'A';
    return c;
}

char toLower(char c)
{
    if ('A' <= c && c <= 'Z')
        return c - 'A' + 'a';
    return c;
}

int main()
{
    char inp[1111];
    scanf("%s", inp);

    int len = strlen(inp);
    int upper = 0, lower = 0;
    for (int i = 0; i < len; i++) {
        char c = inp[i];
        if ('a' <= c && c <= 'z')
            lower++;
        else
            upper++;
    }

    if (upper > lower)
        for (int i = 0; i < len; i++)
            cout << toUpper(inp[i]);
    else
        for (int i = 0; i < len; i++)
            cout << toLower(inp[i]);

    cout << endl;

    return 0;
}