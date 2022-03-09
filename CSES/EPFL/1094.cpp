#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    int max_so_far = 0;
    long long int ans = 0; // watch out for overflow of int32
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);

        if (num >= max_so_far) {
            max_so_far = num;
        } else {
            ans += max_so_far - num;
        }
    }

    printf("%lld\n", ans);

    return 0;
}
