#include <bits/stdc++.h>

using namespace std;

int main()
{
    char inp[100100] = {'\0'};
    scanf("%s", inp);
    int n = strlen(inp);

    {
        stack<char> s;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s.size() > 0 && s.top() == inp[i])
                s.pop(), cnt++;
            else
                s.push(inp[i]);
        }
        printf("%s\n", cnt % 2 == 0 ? "No" : "Yes");
    }
    /*
    {
        // Wrong answer on case abbcca!
        int cnt = 0;
        bool used[n];

        memset(used, false, sizeof(used));
        for (int i = 1; i < n; i++) {
            for (int j = 0; i - j - 1 >= 0 && i + j < n; j++) {
                if (inp[i + j] == inp[i - 1 - j] && used[i + j] == false &&
                    used[i - 1 - j] == false) {
                    used[i + j] = used[i - 1 - j] = true;
                    // printf("%d %d\n", i, j);
                    cnt++;
                } else
                    break; // WTF?
            }
        }
        printf("%s\n", cnt % 2 == 0 ? "No" : "Yes");
    }
    */

    return 0;
}
