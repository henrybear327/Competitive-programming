#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    sort(arr, arr + n);
    reverse(arr, arr + n);

    int ans = 0;
    for (int i = 1; i < n; i += 2) {
        ans += arr[i - 1] - arr[i];
    }
    printf("%d\n", ans);

    return 0;
}
