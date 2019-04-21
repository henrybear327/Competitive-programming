#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    stack<char> s;
    char inp[100010];
    scanf("%s", inp);

    int len = strlen(inp);
    for (int i = 0; i < len; i++) {
        if (s.size() == 0)
            s.push(inp[i]);
        else {
            if (s.top() != inp[i])
                s.pop();
            else
                s.push(inp[i]);
        }
    }

    printf("%d\n", len - (int)s.size());

    return 0;
}
