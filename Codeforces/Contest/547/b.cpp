#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);

    int inp[n * 2];
    for (int i = 0; i < n; i++)
        scanf("%d", &inp[i]), inp[i + n] = inp[i];

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (inp[i] == 1) {
            int j = i;
            while (j < 2 * n && inp[j] == 1)
                j++;
            ans = max(j - i, ans);
            i = j - 1;
        }
    }
    printf("%d\n", ans);

    return 0;
}
