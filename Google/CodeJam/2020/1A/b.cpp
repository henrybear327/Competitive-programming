#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

void solve()
{
    int n;
    scanf("%d", &n);

    if (n <= 30) {
        for (int i = 1; i <= n; i++) {
            printf("%d 1\n", i);
        }
    } else {
        vector<int> used;
        n -= 30;
        for (int i = 0; i < 31; i++)
            if ((n >> i) & 1)
                used.push_back(i);

        int ones = 0, cur = 1;
        for (int i = 0; i < (int)used.size(); i++) {
            int target = used[i] + 1;
            bool isLeft = (i % 2 == 0 ? true : false);

            while (cur < target) {
                if (isLeft) {
                    printf("%d %d\n", cur, 1);
                } else {
                    printf("%d %d\n", cur, cur);
                }

                cur++;
                ones++;
            }

            for (int j = 0; j < cur; j++) {
                if (isLeft) {
                    printf("%d %d\n", cur, j + 1);
                } else {
                    printf("%d %d\n", cur, cur - j);
                }
            }

            cur++;
        }

        // printf("left over\n");
        bool isLeft = used.size() % 2 == 0 ? true : false;
        for (int i = 0; i < 30 - ones; i++) {
            if (isLeft) {
                printf("%d 1\n", cur);
            } else {
                printf("%d %d\n", cur, cur);
            }
            cur++;
        }
    }
}

int main()
{
    int ncase;
    scanf("%d", &ncase);

    for (int i = 1; i <= ncase; i++) {
        printf("Case #%d:\n", i);
        solve();
    }

    return 0;
}
