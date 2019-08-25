#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    // 500 * 500 * 1024 = 25 * 10^7 = 2.5 * 10^8
    vector<int> ans[1024]; // crucial observation -> XOR value will always be
    // within [0, 1023]
    for (int i = 0; i < n; i++) {
        vector<int> newAns[1024];
        for (int j = 0; j < m; j++) {
            int num;
            scanf("%d", &num);

            if (i == 0) {
                if (newAns[num].size() == 0)
                    newAns[num].push_back(j);
            } else {
                for (int k = 0; k < 1024; k++) {
                    if (ans[k].size() > 0 && newAns[num ^ k].size() == 0) { // this optimization is a must -> vector is slow
                        vector<int> tmp(ans[k]);
                        tmp.push_back(j);
                        newAns[num ^ k] = tmp;
                    }
                }
            }
        }

        for (int j = 0; j < 1024; j++)
            ans[j] = newAns[j];
    }

    for (int i = 1; i < 1024; i++) {
        if (ans[i].size() > 0) {
            // print ans
            printf("TAK\n");
            for (auto j : ans[i])
                printf("%d ", j + 1);
            return 0;
        }
    }

    printf("NIE\n");

    return 0;
}
