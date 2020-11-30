#include <bits/stdc++.h>

using namespace std;

set<string> res;
string tmp;
bool seen[8] = {false};
void dfs(string str, int idx)
{
    if (idx == (int)str.length()) {
        res.insert(tmp);
        return;
    }

    for (int i = 0; i < (int)str.length(); i++) {
        if (seen[i])
            continue;
        seen[i] = true;
        tmp += str[i];
        dfs(str, idx + 1);
        tmp.pop_back();
        seen[i] = false;
    }
}

int main()
{
    char inp[8 + 3];
    scanf("%s", inp);

    sort(inp, inp + strlen(inp));
    dfs(inp, 0);

    printf("%d\n", (int)res.size());
    for (auto i : res)
        printf("%s\n", i.c_str());

    return 0;
}
