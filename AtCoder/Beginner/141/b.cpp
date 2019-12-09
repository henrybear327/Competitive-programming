#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    char inp[111];
    scanf("%s", inp);

    bool ok = true;
    for (int i = 0; i < strlen(inp); i++) {
        if (i % 2 == 0 && inp[i] == 'L')
            ok = false;
        else if (i % 2 == 1 && inp[i] == 'R')
            ok = false;
    }

    printf("%s\n", ok ? "Yes" : "No");

    return 0;
}
