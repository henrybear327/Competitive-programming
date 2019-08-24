#include <bits/stdc++.h>

using namespace std;

int n;
char inp[200010];
/*
vector<char> ans;
int run(int starting)
{
    // greedy should work, because for every pair of char, they must all be
valid
    // special case when odd, e.g. baa
    // wrong answer case for this approach -> aabbaa
    ans.clear();
    for (int i = starting; i + 1 < n; i += 2) {
        if (inp[i] == inp[i + 1]) {
            continue;
        }

        ans.push_back(inp[i]);
        ans.push_back(inp[i + 1]);
    }

    return (n % 2 == 0 ? n : n - 1) - (int)ans.size();
}
*/

int main()
{
    scanf("%d", &n);
    scanf("%s", inp);

    /*
    if (n % 2 == 0) {
        run(0);
    } else {
        int one = run(0);
        int two = run(1);

        if (one < two) {
            run(0);
        }
    }
    */

    vector<char> ans;
    // greedy works
    // we need to keep the remove count as low as possible, so we keep as many valid pair as we can
    // if it's the same char, throwing both is worse than preseving one
    // so we should preserve either one down and discard the other, and continue the matching
    for (int i = 0; i < n; i++) {
        if ((int)ans.size() % 2 == 0)
            ans.push_back(inp[i]);
        else if (inp[i] != ans.back())
            ans.push_back(inp[i]);
    }

    if ((int)ans.size() % 2 == 1)
        ans.pop_back();

    printf("%d\n", n - (int)ans.size());
    for (auto i : ans)
        printf("%c", i);
    printf("\n");

    return 0;
}
