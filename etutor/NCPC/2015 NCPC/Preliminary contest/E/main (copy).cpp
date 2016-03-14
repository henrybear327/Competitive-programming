#include <bits/stdc++.h>

using namespace std;

int T[1024600][210];

int main()
{
    int target, n;
    while(scanf("%d %d", &target, &n) == 2 && target != 0) {

        vector<int> inp;
        for(int i = 0; i < n; i++) {
            int tmp;
            scanf("%d", &tmp);

            inp.push_back(tmp);
        }

        sort(inp.begin(), inp.end());

        int ans = 0;

        for(int i = 0; i < n; i++) {
            printf("inp %d\n", inp[i]);
            for(int j = 0; j <= target; j++) {
                if(j == 0) {
                    T[i][0] = 0;
                    continue;
                }
                if(i == 0) {
                    if(j >= inp[i]) {
                        T[i][j] = inp[i];
                    } else {
                        T[i][j] = 0;
                    }
                } else {
                    if(inp[i] < j)
                        T[i][j] = T[i - 1][j];
                    else {
                        T[i][j] = max(T[i - 1][j], inp[i] + T[i - 1][j - inp[i]]);
                    }
                }

                ans = T[i][j] <= target ? max(ans, T[i][j]) : ans;
            }
        }

        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
                printf("%d ", T[i][j]);
            }
            printf("\n");
        }

        printf("%d\n", ans);
    }
    return 0;
}
