#include <bits/stdc++.h>

using namespace std;

int main()
{
    char inp[111111];
    scanf("%s", inp);

    int n = strlen(inp);
    for (int i = 0; i < n; i += 2)
        printf("%c", inp[i]);
}
