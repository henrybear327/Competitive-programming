#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const char *color = "RGB";

int main()
{
    int n;
    scanf("%d", &n);

    char inp[n];
    scanf("%s", inp);

    int ans = INT_MAX;
    char str[n + 3] = {'\0'};
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            if (i == j)
                continue;
            for (int k = 0; k < 3; k++) {
                if (j == k || i == k)
                    continue;
                int cnt = 0;
                char tmp[n];
                char perm[3] = {color[i], color[j], color[k]};
                for (int x = 0; x < n; x++) {
                    if (perm[x % 3] != inp[x])
                        cnt++;
                    tmp[x] = perm[x % 3];
                }

                if (ans > cnt) {
                    ans = cnt;
                    strncpy(str, tmp, n);
                }
            }
        }

    printf("%d\n%s\n", ans, str);

    return 0;
}
