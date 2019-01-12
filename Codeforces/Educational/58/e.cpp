#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    char inp[111];
    fgets(inp, 111, stdin);
    int n;
    sscanf(inp, "%d", &n);

    int h = 0, w = 0;
    while (n--) {
        fgets(inp, 111, stdin);
        // printf("inp = %s", inp);

        char op;
        int x, y;
        sscanf(inp, "%c %d %d", &op, &x, &y);
        if (x > y)
            swap(x, y);
        // printf("%c %d %d\n", op, x, y);

        if (op == '+') {
            w = max(w, x);
            h = max(h, y);
        } else {
            if (w <= x && h <= y)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }

    return 0;
}
