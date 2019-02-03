#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    char inp[1111];
    scanf("%s", inp);

    int n = strlen(inp);
    bool has[2] = {false};
    for (int i = 0; i < n; i++) {
        int x, y;
        if (inp[i] == '0') {
            if (has[0] == false)
                x = 3, y = 1;
            else
                x = 1, y = 1;

            has[0] = !has[0];
        } else {
            if (!has[1])
                x = 1, y = 3;
            else
                x = 1, y = 1;
            has[1] = !has[1];
        }

        printf("%d %d\n", x, y);
    }

    return 0;
}
