#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> ans[2];

#define inv(x) ((x & 1) ^ 1)

int power(int p)
{
    if (p == 0)
        return 1;
    return 10 * power(p - 1);
}

void print(int x)
{
    int ans[10], i = 0;
    while (x) {
        ans[i++] = x % 10;
        x /= 10;
    }
    for (int j = i - 1; j >= 0; j--)
        printf("%d%c", ans[j], j == 0 ? '\n' : ' ');
}

void solve(int cur)
{
    if (cur == 1) {
        ans[cur % 2].push_back(1);
        solve(cur + 1);
        return;
    }
    if (cur > n) {
        // print ans
        for (int i = 0; i < (int)ans[inv(cur)].size(); i++)
            print(ans[inv(cur)][i]);
        return;
    }

    ans[cur % 2].clear();
    for (int i = 0; i < (int)ans[inv(cur)].size(); i++) {
        int num[cur - 1] = {0};
        int number = ans[inv(cur)][i], idx = cur - 2;
        // printf("number %d\n", number);
        while (number != 0) {
            num[idx--] = number % 10;
            number /= 10;
        }

        if (i % 2 == 0) {
            for (int j = cur - 1; j >= 0; j--) {
                int tmp[cur];
                tmp[j] = cur;
                for (int k = 0; k <= cur; k++) {
                    if (k < j)
                        tmp[k] = num[k];
                    else if (k > j)
                        tmp[k] = num[k - 1];
                }

                int toput = 0;
                for (int k = 0; k < cur; k++) {
                    toput *= 10;
                    toput += tmp[k];
                }
                ans[cur % 2].push_back(toput);
                // printf("level %d toput %d\n", cur, toput);
            }
        } else {
            for (int j = 0; j < cur; j++) {
                int tmp[cur];
                tmp[j] = cur;
                for (int k = 0; k <= cur; k++) {
                    if (k < j)
                        tmp[k] = num[k];
                    else if (k > j)
                        tmp[k] = num[k - 1];
                }

                int toput = 0;
                for (int k = 0; k < cur; k++) {
                    toput *= 10;
                    toput += tmp[k];
                }
                ans[cur % 2].push_back(toput);
                // printf("level %d toput %d\n", cur, toput);
            }
        }
    }

    solve(cur + 1);
}

int main()
{
    scanf("%d", &n);

    solve(1);

    return 0;
}
