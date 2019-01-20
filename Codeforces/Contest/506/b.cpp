#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);

    int inp[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &inp[i]);

    int mx = 0;
    int left = 0, right = 1;
    while (right < n) {
        if (inp[right - 1] * 2 >= inp[right]) {
            right++;
        } else {
            mx = max(mx, right - 1 - left + 1);
            left = right;
            right = left + 1;
        }
    }

    mx = max(mx, right - 1 - left + 1);

    printf("%d\n", mx);

    return 0;
}
