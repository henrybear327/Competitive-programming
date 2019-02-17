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

    int left[n], right[n];
    {
        int cnt = 0;
        bool error = false;
        for (int i = 0; i < n; i++) {
            if (cnt > 0 && inp[i] == ')')
                cnt--;
            else if (inp[i] == '(')
                cnt++;
            else
                error = true;

            left[i] = error ? -1 : cnt;
        }
    }

    {
        int cnt = 0;
        bool error = false;
        for (int i = n - 1; i >= 0; i--) {
            if (cnt > 0 && inp[i] == '(')
                cnt--;
            else if (inp[i] == ')')
                cnt++;
            else
                error = true;

            right[i] = error ? -1 : cnt;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int l = i - 1 >= 0 ? left[i - 1] : 0;
        int r = i + 1 < n ? right[i + 1] : 0;
        if (l == -1 || r == -1)
            continue;
        if (inp[i] == ')') {
            if (l + 1 == r)
                ans++;
        } else {
            if (l == r + 1)
                ans++;
        }
    }
    printf("%d\n", ans);

    return 0;
}
