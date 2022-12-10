#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    char inp[22];
    scanf("%s", inp);

    bool ok = true;
    if (strlen(inp) != 8) {
        ok = false;
    } else {
        if (!('A' <= inp[0] && inp[0] <= 'Z')) {
            ok = false;
        }
        if (!('A' <= inp[7] && inp[7] <= 'Z')) {
            ok = false;
        }

        if (!('1' <= inp[1] && inp[1] <= '9')) {
            ok = false;
        }

        for (int i = 2; i <= 6; i++) {
            if (!('0' <= inp[i] && inp[i] <= '9')) {
                ok = false;
            }
        }
    }

    printf("%s\n", ok ? "Yes" : "No");

    return 0;
}
