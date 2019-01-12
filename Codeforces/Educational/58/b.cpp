#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    char inp[500010];
    scanf("%s", inp);

    int len = strlen(inp);
    int cnt[2] = {-1, -1}; // [0] = rightmost pos of : in [:
    int seen = false;
    for (int i = 0; i < len; i++) {
        if (inp[i] == '[') {
            seen = true;
        } else if (inp[i] == ':' && seen) {
            cnt[0] = i;
            break;
        }
    }

    seen = false;
    for (int i = len - 1; i >= 0; i--) {
        if (inp[i] == ']') {
            seen = true;
        } else if (inp[i] == ':' && seen) {
            cnt[1] = i;
            break;
        }
    }

    int col = 0;
    for (int i = cnt[0] + 1; i <= cnt[1] - 1; i++) {
        if (inp[i] == '|')
            col++;
    }

    int tot = -1;
    if (cnt[0] != -1 && cnt[0] != -1 && cnt[0] < cnt[1])
        tot = (4 + col);
    printf("%d\n", tot);

    return 0;
}
