#include <bits/stdc++.h>
// LLONG_MIN LLONG_MAX INT_MIN INT_MAX

using namespace std;

int main()
{
    char inp[100100];
    scanf("%s", inp);

    char pat[100];
    scanf("%s", pat);

    int ans = 0, len = strlen(inp), plen = strlen(pat);
    for (int i = 0; i < len; i++) {
        if (strncmp(inp + i, pat, plen) == 0) {
            ans++;
	    i += plen - 1;
	}
    }

    printf("%d\n", ans);

    return 0;
}
