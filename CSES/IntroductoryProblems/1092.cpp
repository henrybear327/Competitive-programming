#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    scanf("%lld", &n);

    long long total = (1 + n) * n / 2;
    if (total % 2 == 0) {
        vector<int> left, right;
        if (n % 2 == 0) {
            // multiple of 4 only, as [1, 4] = 10, [1, 6] will be odd (odd + even =
            // odd)
            for (int i = 0; i < n / 2; i++) {
                if (i % 2 == 0) {
                    left.push_back(i + 1);
                    left.push_back(n - i);
                } else {
                    right.push_back(i + 1);
                    right.push_back(n - i);
                }
            }
        } else {
            for (int i = 0; i < n / 2; i++) {
                if (i % 2 == 0) {
                    left.push_back(i + 1);
                    left.push_back((n - 1) - i);
                } else {
                    right.push_back(i + 1);
                    right.push_back((n - 1) - i);
                }
            }
            right.push_back(n);
        }

        printf("YES\n");
        printf("%d\n", (int)left.size());
        for (auto i : left)
            printf("%d ", i);
        printf("\n%d\n", (int)right.size());
        for (auto i : right)
            printf("%d ", i);
    } else {
        printf("NO\n");
    }

    return 0;
}
