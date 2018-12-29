#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);

    char inp[n + 3];
    scanf("%s", inp);
    int len = strlen(inp);
    inp[len] = 'S';
    inp[len + 1] = '\0';

    int group = 0;
    for (int i = 0; i < n; i++) {
        if (inp[i] == 'S')
            continue;
        else {
            if (i == 0)
                group++;
            else if (inp[i - 1] == 'S')
                group++;
        }
    }

    int ans = 0, prev = 0;
    bool flag = false;
    int l = INT_MAX, r = INT_MIN;
    for (int i = 0; i < n + 1; i++) {
        if (inp[i] == 'S') {
            if (l == INT_MAX)
                continue;

            // if more than 1 group of gold, self length can be extended by 1
            if (group > 1)
                ans = max(ans, r - l + 1 + 1); // SGGSGGS
            else
                ans = max(ans, r - l + 1); // SSGGGSS

            if (flag) // SGGSGGS -> SGGGGSS (one s between gg groups)
                ans = max(ans, prev + r - l + 1 + (group > 2));
            prev = r - l + 1;

            if (i + 1 < n && inp[i + 1] == 'G')
                flag = true;
            else
                flag = false;
            l = INT_MAX;
            r = INT_MIN;
        } else {
            l = min(l, i);
            r = max(r, i);
        }
    }

    printf("%d\n", ans);

    return 0;
}
