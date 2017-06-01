#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

void solve()
{
    char inp[100010];
    scanf("%s", inp);

    int cnt = 0;
    int len = strlen(inp);

    vector<char> seq;
    seq.push_back(inp[0]);
    for (int i = 1; i < len; i++) {
        if (inp[i] != seq[(int)seq.size() - 1])
            seq.push_back(inp[i]);
    }

    for (int i = 0; i < (int)seq.size(); i++)
        if (seq[i] == '1')
            cnt++;

    printf("%s\n", cnt == 1 ? "YES" : "NO");

    /*
    for(int i = 0; i < len; i++) {
            if(cnt % 2 == 0) {
                    if(inp[i] == '1') {
                            if(cnt != 0) {
                                    printf("NO\n");
                                    return;
                            } else {
                                    cnt++;
                            }
                    }
            } else {
                    if(inp[i] == '0')
                            cnt++;
            }
    }

    printf("%s\n", cnt != 0 ? "YES" : "NO");
    */
}

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while (ncase--) {
        solve();
    }

    return 0;
}
