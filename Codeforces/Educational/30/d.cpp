#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

void mergeSort(int ans[], int l, int r, int &k)
{
    if (r - l == 1) {
        return;
    }

    if (k > 0) {
        k -= 2;
    } else {
        reverse(ans + l, ans + r);
        return;
    }

    int mid = (l + r) / 2;
    mergeSort(ans, l, mid, k);
    mergeSort(ans, mid, r, k);
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    k--;
    if (k % 2 == 1) {
        printf("-1\n");
        return 0;
    }

    int ans[n];
    for (int i = 0; i < n; i++)
        ans[i] = n - i;

    mergeSort(ans, 0, n, k);

    if (k > 0)
        printf("-1\n");
    else
        for (auto i : ans)
            printf("%d ", i);

    return 0;
}
