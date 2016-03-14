#include <bits/stdc++.h>
// LLONG_MIN LLONG_MAX INT_MIN INT_MAX


using namespace std;

int main()
{
    int n, x;
    while (scanf("%d %d", &n, &x) == 2) {
        char inp[n + 10];
        scanf("%s", inp);

        string ans;

        int location = x - 1, cnt;
        scanf("%d", &cnt);
        char command[cnt + 10];
        scanf("%s", command);

        ans.push_back(inp[location]);
        for (int i = 0; i < cnt; i++) {
            if (command[i] == 'R')
                location++;
            else
                location--;
            ans.push_back(inp[location]);
        }

        printf("%s\n", ans.c_str());
    }

    return 0;
}
