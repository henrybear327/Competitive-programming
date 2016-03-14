#include <bits/stdc++.h>
// LLONG_MIN LLONG_MAX INT_MIN INT_MAX

using namespace std;

int get_sign(char inp)
{
    if (inp == '<' || inp == '>')
        return 1;
    else if (inp == '{' || inp == '}')
        return 2;
    else if (inp == '[' || inp == ']')
        return 3;
    else
        return 4;
}

int main()
{
    char inp[1000100];
    scanf("%s", inp);

    stack<int> s;
    int len = strlen(inp);
    int ans = 0;
    for (int i = 0; i < len; i++) {
        if (inp[i] == '<' || inp[i] == '{' || inp[i] == '[' || inp[i] == '(')
            s.push(inp[i]);
        else {
            if (s.empty() == true) {
                ans = -1;
                break;
            }

            char curr = s.top();
            s.pop();

            if (get_sign(curr) != get_sign(inp[i])) {
                ans++;
            }
        }
    }
    if (s.empty() == false)
        ans = -1;

    if (ans == -1)
        printf("Impossible\n");
    else
        printf("%d\n", ans);

    return 0;
}
