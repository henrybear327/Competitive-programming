#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b;
    while (scanf("%d %d", &a, &b) == 2) {
        vector<int> ans;
        while (a && b) {
            ans.push_back(abs(a % 10 - b % 10));
            a /= 10;
            b /= 10;
        }

        bool ok = false;
        for (int i = ans.size() - 1; i >= 0; i--) {
            if (ans[i] == 0 && ok == false)
                continue;
            else if (ans[i] != 0 && ok == false) {
                ok = true;
                printf("%d", ans[i]);
            } else
                printf("%d", ans[i]);
        }
        if (ok == false) // come on~~
            printf("0");
        printf("\n");
    }

    return 0;
}
