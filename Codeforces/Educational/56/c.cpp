#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    ll b[n / 2];
    for (int i = 0; i < n / 2; i++)
        scanf("%lld", &b[i]);

    ll a[n];
    a[0] = 0;
    a[n - 1] = b[0];
    for (int i = 1; i < n / 2; i++) {
        int j = n - 1 - i;

        // a[i - 1], left, ..., right, a[j + 1]
        // left + right = b[i]

        ll left = a[i - 1];
        ll right = b[i] - left;

        // cout << "1"
        //   << " " << left << " " << right << endl;
        if (right <= a[j + 1]) {
            // cout << "in" << endl;
            a[i] = left;
            a[j] = right;
            continue;
        }

        right = a[j + 1];
        left = b[i] - right;

        // cout << "2"
        //   << " " << left << " " << right << endl;
        a[i] = left;
        a[j] = right;
    }

    for (auto i : a)
        printf("%lld ", i);

    return 0;
}
